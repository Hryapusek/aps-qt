#ifndef EVENT_HPP
#define EVENT_HPP

#include "Order.hpp"

class EventType
{
public:
  enum EventType_
  {
    ORDER_CREATED,
    DEVICE_FINISHED
  };

  EventType(EventType_ type) :
    type_(type)
  { }

  bool operator==(const EventType &rhs)
  {
    return this->type_ == rhs.type_;
  }

private:
  EventType_ type_;
};

class Event
{
public:
  Event(EventType type, double time, Order order);
  EventType type() const;
  double time() const;
  Order order() const;
private:
  EventType type_;
  double time_;
  Order order_;
};

#endif
