#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "Order.hpp"
#include <boost/circular_buffer.hpp>

class Buffer
{
public:
  Buffer(int bufferSize);
  /// @param time used only for statistics
  /// @throw std::exception if full
  void push_back(Order order, double time);
  void pop_front(double time);
  /// @param time used only for statistics
  const Order &nextOrder(double time);
  bool hasSpace() const noexcept;
  bool empty() const noexcept;

private:
  boost::circular_buffer<Order> queue_;
};

#endif
