#include "EventHolder.hpp"
#include <random>
#include <cmath>
#include <ranges>
#include <cassert>
#include <iostream>

EventHolder::EventHolder(const InputParameters &params, BufferGui *bufferGui, DevicesGui *devicesGui, EventsGui *eventsGui, ClientsGui *clientsGui) :
  params_(params),
  bufferGui_(bufferGui),
  devicesGui_(devicesGui),
  eventsGui_(eventsGui),
  clientsGui_(clientsGui)
{
  deviceHolder_ = std::make_unique< DeviceHolder >(params_.nDevices, params_.minDeviceTime, params_.maxDeviceTime);
  buffer_ = std::make_unique< Buffer >(params_.bufferSize, bufferGui_, eventsGui_);
  stats_ = std::make_unique< Statistics > (params_.nDevices);
  QObject::connect(buffer_.get(), &Buffer::orderRejected, stats_.get(), &Statistics::addRejected);
  calcEventsInterval();
  std::cout << "Interval: " << eventsInterval_ << '\n';
  double currentTime = 0;
  int clientId = 0;
  while (currentTime < params_.time)
  {
    events_.insert(Event(EventType::ORDER_CREATED, currentTime, Order::makeOrder(clientId % params_.nClients, currentTime)));
    calcEventsInterval();
    currentTime += eventsInterval_;
    ++clientId;
  }
  for (const auto &event : events_ | std::views::take(params_.nClients))
    clientsGui_->update(event.order());
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

double EventHolder::getRejectProbability() const
{
  return stats_->getRejectProbability();
}

double EventHolder::getAvgTimeInSystem() const
{
  return stats_->getAvgTimeInSystem();
}

double EventHolder::getDeviceLoad() const
{
  return stats_->getDeviceLoad();
}

void EventHolder::calcEventsInterval()
{
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_real_distribution< double > distribution(0.3, 0.6);
  auto r = distribution(engine);
  auto lambda = params_.lambda;
  eventsInterval_ = -1 / lambda * std::log(r);
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
  auto nextCreated = std::ranges::find_if(events_, [&](const Event &e) {
    return e.order().clientId() == event.order().clientId() &&
          e.type() == EventType::ORDER_CREATED;
  });
  if (nextCreated != events_.cend())
  {
    clientsGui_->update(nextCreated->order());
  }
  eventsGui_->addEvent(event.time(), event.order(), "CREATED");
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
  stats_->addDeviceProcessingTime(time, finishTime);
  devicesGui_->process(order);
  eventsGui_->addEvent(time, order, "PUT IN DEVICE");
  return finishTime;
}

void EventHolder::finishProcessing(Order order, double time)
{
  eventsGui_->addEvent(time, order, "OUT OF DEVICE");
  devicesGui_->finishProcessing(order);
  eventsGui_->addSuccess();
  stats_->addSuccessOrder(order, time);
}
