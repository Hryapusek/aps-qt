#include "Buffer.hpp"
#include <iostream>

Buffer::Buffer(int bufferSize) :
  queue_(bufferSize)
{}

void Buffer::push_back(Order order, double time)
{
  if (queue_.full())
  {
    auto orderToReject = queue_.front();
    queue_.pop_front();
    queue_.push_back(std::move_if_noexcept(order));
    std::cerr << "Order rejected\n";
    // TODO notify that order was rejected
  }
  else
  {
    queue_.push_back(std::move_if_noexcept(order));
    std::cerr << "Order put in buffer " << queue_.size() << " " << queue_.empty() << '\n';
  }
}

void Buffer::pop_front(double time)
{
  queue_.pop_front();
}

const Order &Buffer::nextOrder(double time)
{
  std::cerr << "nextOrder " << queue_.size() << " " << queue_.empty() << '\n';
  if (queue_.empty())
    throw std::exception();
  return queue_.back();
}

bool Buffer::hasSpace() const noexcept
{
  return !queue_.full();
}

bool Buffer::empty() const noexcept
{
  return queue_.empty();
}
