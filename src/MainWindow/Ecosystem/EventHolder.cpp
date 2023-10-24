#include "EventHolder.hpp"
#include <random>
#include <cmath>
#include <iostream>
#include <ranges>
#include <cassert>

EventHolder::EventHolder(const InputParameters &params, BufferGui *bufferGui, DevicesGui *devicesGui) :
  params_(params),
  bufferGui_(bufferGui),
  devicesGui_(devicesGui)
{
  deviceHolder_ = std::make_unique< DeviceHolder >(params_.nDevices, params_.minDeviceTime, params_.maxDeviceTime);
  buffer_ = std::make_unique< Buffer >(params_.bufferSize, bufferGui_);
  eventsInterval_ = calcEventsInterval();
  std::cerr << "Interval: " << eventsInterval_ << '\n';
  for (const auto clientId : std::ranges::views::iota(0, params_.nClients))
  {
    if (params_.time < clientId * eventsInterval_)
      break;
    events_.insert(Event(EventType::ORDER_CREATED, clientId * eventsInterval_, Order::makeOrder(clientId)));
    std::cerr << "Order name: " << events_.rbegin()->order().name() << '\n';
  }
  printEvents();
}

void EventHolder::step()
{
  if (events_.empty())
    return;
  auto lastEvent = *events_.begin();
  events_.erase(events_.begin());
  processEvent(lastEvent);
  printEvents();
}

double EventHolder::calcEventsInterval()
{
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_real_distribution< double > distribution(0, 1);
  auto r = distribution(engine);
  auto lambda = params_.lambda;
  return -1 / lambda * std::log(r);
}

void EventHolder::processEvent(const Event &event)
{
  if (event.type() == EventType::ORDER_CREATED)
    processOrderCreatedEvent(event);
  else if (event.type() == EventType::DEVICE_FINISHED)
    processDeviceFinishedEvent(event);
}

void EventHolder::rejectOrder(const Order &order)
{
  std::cerr << "__func__ - Implement me\n";
}

void EventHolder::processOrderCreatedEvent(const Event &event)
{
  assert(("Event type must be OrderCreated", event.type() == EventType::ORDER_CREATED));
  { // Put another OrderCreated in array after nClients * eventsInterval_ time.
    // New orders must be generated every "eventsInterval_" time
    auto newEventTime = event.time() + params_.nClients * eventsInterval_;
    if (newEventTime < params_.time)
    {
      auto newEventOrder = Order::makeOrder(event.order().clientId());
      std::cerr << "ClientId " << event.order().clientId() << '\n';
      auto newEvent = Event(EventType::ORDER_CREATED, newEventTime, std::move(newEventOrder));
      events_.insert(std::move(newEvent));
    }
  }
  if (deviceHolder_->hasSpace(event.time()))
  {
    auto finishTime = deviceHolder_->processOrder(event.order(), event.time());
    devicesGui_->process(event.order());
    Event deviceFinishedEvent = Event(EventType::DEVICE_FINISHED, finishTime, event.order());
    events_.insert(std::move(deviceFinishedEvent));
  }
  else
  {
    buffer_->addOrder(event.order(), event.time());
  }
}

void EventHolder::processDeviceFinishedEvent(const Event &event)
{
  assert(("Event type must be DEVICE_FINISHED", event.type() == EventType::DEVICE_FINISHED));
  devicesGui_->finishProcessing(event.order());
  if (!buffer_->empty())
  {
    Order orderToProcess = buffer_->nextOrder(event.time());
    buffer_->moveOrder(event.time());
    auto finishTime = deviceHolder_->processOrder(orderToProcess, event.time());
    devicesGui_->process(orderToProcess);
    Event deviceFinishedEvent = Event(EventType::DEVICE_FINISHED, finishTime, orderToProcess);
    events_.insert(std::move(deviceFinishedEvent));
  }
}

void EventHolder::printEvents()
{
  using namespace std::ranges;
  std::copy_n((events_ | views::transform([](const Event &e) {
    return e.type().to_string();
  })).begin(), std::min(3ul, events_.size()), std::ostream_iterator< std::string >(std::cerr, " "));
  std::cerr << '\n';
}
