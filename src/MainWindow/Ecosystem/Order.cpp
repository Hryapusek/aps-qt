#include "Order.hpp"
#include <iostream>

std::map<Order::ClientId_t, Order::OrderId_t> Order::clientNextOrderId;

Order Order::makeOrder(int clientId)
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
  std::cerr << "Order " << clientId << " " << orderId << '\n';
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
