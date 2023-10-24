#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <map>

class Order
{
public:
  using ClientId_t = int;
  using OrderId_t = int;

  static Order makeOrder(int clientId);

  const std::string &name() const;
  int clientId() const;

  bool operator==(const Order &rhs) const noexcept;

private:
  static std::map< ClientId_t, OrderId_t > clientNextOrderId;
  ClientId_t clientId_;
  OrderId_t orderId_;
  std::string name_;
  Order(int clientId, OrderId_t orderId, std::string name);
};

#endif
