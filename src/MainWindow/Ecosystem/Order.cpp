#include "Order.hpp"

std::map<Order::ClientId_t, Order::OrderId_t> Order::clientNextOrderId;

Order Order::makeOrder(int clientId)
{
  auto orderId = Order::clientNextOrderId.contains(clientId) ? Order::clientNextOrderId[clientId]++ : Order::clientNextOrderId[clientId] = 0;
  return Order(clientId, orderId, "И" + std::to_string(clientId) + "_" + std::to_string(orderId));
}

const std::string &Order::name() const
{
  return name_;
}

int Order::clientId() const
{
  return clientId_;
}

Order::Order(ClientId_t clientNum, OrderId_t orderId, std::string name) :
  clientId_(clientNum),
  orderId_(orderId),
  name_(std::move(name))
{}
