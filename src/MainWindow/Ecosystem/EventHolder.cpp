#include "EventHolder.hpp"
#include <random>
#include <cmath>
#include <iostream>
#include <ranges>
#include <cassert>

EventHolder::EventHolder(const InputParameters &params)
{
  params_ = params;
  eventsInterval_ = calcEventsInterval();
  std::cerr << "Interval: " << eventsInterval_ << '\n';
  events_ = std::make_unique< std::set< Event, std::function< bool(const Event &lhs, const Event &rhs) > > >(
    [](const Event &lhs, const Event &rhs) {
    return lhs.time() < rhs.time();
  });
  for (const auto clientId : std::ranges::views::iota(0, params_.nClients))
  {
    events_->insert(Event(EventType::ORDER_CREATED, clientId * eventsInterval_, Order::makeOrder(clientId)));
  }
}

void EventHolder::step()
{
  if (events_->empty())
    return;
  auto lastEvent = *events_->begin();
  events_->erase(events_->begin());
  processEvent(lastEvent);
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
  {
    processOrderCreatedEvent(event);
    
  }
}

void EventHolder::processOrderCreatedEvent(const Event &event)
{
  assert(("Event type must be OrderCreated", event.type() == EventType::ORDER_CREATED));
  {
    auto newEventTime = event.time() + params_.nClients * eventsInterval_;
    if (newEventTime < params_.time)
    {
      auto newEventOrder = Order::makeOrder(event.order().clientId());
      auto newEvent = Event(EventType::ORDER_CREATED, newEventTime, std::move(newEventOrder));
      events_->insert(std::move(newEvent));
    }
  }

}
