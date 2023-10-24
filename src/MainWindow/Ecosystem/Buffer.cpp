#include "Buffer.hpp"
#include <iostream>

Buffer::Buffer(int bufferSize, BufferGui *bufferGui) :
  queue_(bufferSize),
  bufferGui_(bufferGui)
{}

void Buffer::addOrder(Order order, double time)
{
  if (queue_.full())
  {
    auto orderToReject = queue_.front();
    queue_.pop_front();
    queue_.push_back(order);
    bufferGui_->pop_front();
    bufferGui_->push_back(order);
    std::cerr << "Order rejected\n";
    // TODO notify that order was rejected
  }
  else
  {
    queue_.push_back(order);
    bufferGui_->push_back(order);
    std::cerr << "Order put in buffer " << queue_.size() << " " << queue_.empty() << '\n';
  }
}

void Buffer::moveOrder(double time)
{
  queue_.pop_front();
  bufferGui_->pop_front();
}

const Order &Buffer::nextOrder(double time)
{
  std::cerr << "nextOrder " << queue_.size() << " " << queue_.empty() << '\n';
  if (queue_.empty())
    throw std::exception();
  return queue_.front();
}

bool Buffer::hasSpace() const noexcept
{
  return !queue_.full();
}

bool Buffer::empty() const noexcept
{
  return queue_.empty();
}
