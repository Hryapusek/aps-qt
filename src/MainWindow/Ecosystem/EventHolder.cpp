#include "EventHolder.hpp"
#include <random>
#include <cmath>
#include <ranges>
#include <cassert>
#include <iostream>

EventHolder::EventHolder(const InputParameters &params, BufferGui *bufferGui, DevicesGui *devicesGui, EventsGui *eventsGui) :
  params_(params),
  bufferGui_(bufferGui),
  devicesGui_(devicesGui),
  eventsGui_(eventsGui)
{
  deviceHolder_ = std::make_unique< DeviceHolder >(params_.nDevices, params_.minDeviceTime, params_.maxDeviceTime);
  buffer_ = std::make_unique< Buffer >(params_.bufferSize, bufferGui_, eventsGui_);
  eventsInterval_ = calcEventsInterval();
  std::cout << "Interval: " << eventsInterval_ << '\n';
  for (const auto clientId : std::ranges::views::iota(0, params_.nClients))
  {
    if (params_.time < clientId * eventsInterval_)
      break;
    events_.insert(Event(EventType::ORDER_CREATED, clientId * eventsInterval_, Order::makeOrder(clientId)));
  }
}

void EventHolder::step()
{
  if (events_.empty())
    return;
  auto lastEvent = *events_.begin();
  events_.erase(events_.begin());
  processEvent(lastEvent);
}

bool EventHolder::isFinished() const
{
  return events_.empty();
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

void EventHolder::processOrderCreatedEvent(const Event &event)
{
  assert(("Event type must be OrderCreated", event.type() == EventType::ORDER_CREATED));
  eventsGui_->addEvent(event.time(), event.order(), "CREATED");
  { // Put another OrderCreated in array after nClients * eventsInterval_ time.
    // New orders must be generated every "eventsInterval_" time
    auto newEventTime = event.time() + params_.nClients * eventsInterval_;
    if (newEventTime < params_.time)
    {
      auto newEventOrder = Order::makeOrder(event.order().clientId());
      auto newEvent = Event(EventType::ORDER_CREATED, newEventTime, std::move(newEventOrder));
      events_.insert(std::move(newEvent));
    }
  }
  if (deviceHolder_->hasSpace(event.time()))
  {
    buffer_->addOrder(event.order(), event.time());
    buffer_->popOrder(event.time());
    auto finishTime = processOrder(event.order(), event.time());
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
  finishProcessing(event.order(), event.time());
  if (!buffer_->empty())
  {
    Order orderToProcess = buffer_->nextOrder();
    buffer_->popOrder(event.time());
    auto finishTime = processOrder(orderToProcess, event.time());
    Event deviceFinishedEvent = Event(EventType::DEVICE_FINISHED, finishTime, orderToProcess);
    events_.insert(std::move(deviceFinishedEvent));
  }
}

double EventHolder::processOrder(Order order, double time)
{
  auto finishTime = deviceHolder_->processOrder(order, time);
  devicesGui_->process(order);
  eventsGui_->addEvent(time, order, "PUT IN DEVICE");
  return finishTime;
}

void EventHolder::finishProcessing(Order order, double time)
{
  eventsGui_->addEvent(time, order, "OUT OF DEVICE");
  devicesGui_->finishProcessing(order);
  eventsGui_->addSuccess();
}
