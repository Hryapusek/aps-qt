#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "Order.hpp"

#include <boost/circular_buffer.hpp>
#include "../BufferGui.hpp"
#include "../EventsGui.hpp"

class Buffer
{
public:
  Buffer(int bufferSize, BufferGui *bufferGui, EventsGui *eventsGui);
  /// @param time used only for statistics
  void addOrder(Order order, double time);
  void popOrder(double time);
  /// @param time used only for statistics
  [[nodiscard]] const Order &nextOrder();
  [[nodiscard]] bool hasSpace() const noexcept;
  [[nodiscard]] bool empty() const noexcept;

private:
  boost::circular_buffer<Order> queue_;
  BufferGui *bufferGui_;
  EventsGui *eventsGui_;
};

#endif
