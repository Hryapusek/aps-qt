#ifndef CLIENTS_GUI_HPP
#define CLIENTS_GUI_HPP

#include <QTableWidget>
#include "MainWindow/Ecosystem/Order.hpp"

class ClientsGui
{
  enum Column
  {
    INDEX,
    TIME,
    ORDER_NAME,
  };
public:
  ClientsGui(QTableWidget *table, int nClients);
  void update(Order order);

private:
  QTableWidget *table_ = nullptr;
  std::unique_ptr< QTableWidgetItem > itemProto_;
};

#endif
