#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "Order.hpp"
#include "../BufferGui.hpp"
#include <boost/circular_buffer.hpp>

class Buffer
{
public:
  Buffer(int bufferSize, BufferGui *bufferGui);
  /// @param time used only for statistics
  void push_back(Order order, double time);
  void pop_front(double time);
  /// @param time used only for statistics
  [[nodiscard]] const Order &nextOrder(double time);
  [[nodiscard]] bool hasSpace() const noexcept;
  [[nodiscard]] bool empty() const noexcept;

private:
  boost::circular_buffer<Order> queue_;
  BufferGui *bufferGui_;
};

#endif
