#ifndef EVENT_HPP
#define EVENT_HPP

#include "Order.hpp"
#include <utility>

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

  std::string to_string() const noexcept
  {
    switch (type_)
    {
    case ORDER_CREATED:
      return "ORDER_CREATED";
    
    case DEVICE_FINISHED:
      return "DEVICE_FINISHED";
    
    default:
      std::unreachable();
    }
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
  constexpr auto operator<=>(const Event &rhs) const noexcept
  {
    return this->time_ <=> rhs.time_;
  }

private:
  EventType type_;
  double time_;
  Order order_;
};

#endif
