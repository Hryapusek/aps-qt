#include "Order.hpp"

std::map<Order::ClientId_t, Order::OrderId_t> Order::clientNextOrderId;

Order Order::makeOrder(int clientId, double creationTime)
{
  Order::OrderId_t orderId = 0;
  if (Order::clientNextOrderId.contains(clientId))
  {
    orderId = Order::clientNextOrderId.at(clientId)++;
  }
  else
  {
    Order::clientNextOrderId[clientId] = 1;
    orderId = 0;
  }
  return Order(clientId, orderId, "И" + std::to_string(clientId) + "_" + std::to_string(orderId), creationTime);
}

const std::string &Order::name() const
{
  return name_;
}

int Order::clientId() const
{
  return clientId_;
}

double Order::creationTime() const
{
  return creationTime_;
}

bool Order::operator==(const Order &rhs) const noexcept
{
  return this->clientId_ == rhs.clientId_ && this->orderId_ == rhs.orderId_;
}

Order::Order(ClientId_t clientNum, OrderId_t orderId, std::string name, double creationTime) :
  clientId_(clientNum),
  orderId_(orderId),
  name_(std::move(name)),
  creationTime_(creationTime)
{}
