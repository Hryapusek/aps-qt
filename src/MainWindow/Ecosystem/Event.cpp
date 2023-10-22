#include "Event.hpp"

Event::Event(EventType type, double time, Order order) :
  type_(type),
  time_(time),
  order_(order)
{}

EventType Event::type() const
{
  return type_;
}

double Event::time() const
{
  return time_;
}

Order Event::order() const
{
  return order_;
}
