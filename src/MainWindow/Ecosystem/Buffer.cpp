#include "Buffer.hpp"

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
    eventsGui_->addEvent(time, orderToReject, "REJECTED");
    eventsGui_->addCanceled();
    queue_.push_back(order);
    eventsGui_->addEvent(time, order, "PUT IN BUFFER");
    bufferGui_->pop_front();
    bufferGui_->push_back(order);
  }
  else
  {
    queue_.push_back(order);
    eventsGui_->addEvent(time, order, "PUT IN BUFFER");
    bufferGui_->push_back(order);
  }
}

void Buffer::popOrder(double time)
{
  eventsGui_->addEvent(time, queue_.front(), "OUT OF BUFFER");
  queue_.pop_front();
  bufferGui_->pop_front();
}

const Order &Buffer::nextOrder()
{
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
