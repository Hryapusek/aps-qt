#include "Buffer.hpp"
#include <iostream>

Buffer::Buffer(int bufferSize, BufferGui *bufferGui, EventsGui *eventsGui) :
  queue_(bufferSize),
  bufferGui_(bufferGui),
  eventsGui_(eventsGui)
{}

void Buffer::addOrder(Order order, double time)
{
  if (queue_.full())
  {
    auto orderToReject = queue_.front();
    queue_.pop_front();
    eventsGui_->addEvent(time, orderToReject, "ORDER REJECTED");
    eventsGui_->addCanceled();
    queue_.push_back(order);
    eventsGui_->addEvent(time, order, "ORDER PUT IN BUFFER");
    bufferGui_->pop_front();
    bufferGui_->push_back(order);
  }
  else
  {
    queue_.push_back(order);
    eventsGui_->addEvent(time, order, "ORDER PUT IN BUFFER");
    bufferGui_->push_back(order);
    std::cerr << "Order put in buffer " << queue_.size() << " " << queue_.empty() << '\n';
  }
}

void Buffer::popOrder(double time)
{
  eventsGui_->addEvent(time, queue_.front(), "ORDER OUT OF BUFFER");
  queue_.pop_front();
  bufferGui_->pop_front();
}

const Order &Buffer::nextOrder()
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
