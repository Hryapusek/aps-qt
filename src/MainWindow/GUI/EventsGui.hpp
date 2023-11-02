#ifndef EVENTS_GUI_HPP
#define EVENTS_GUI_HPP

#include <QTableWidget>
#include <QSpinBox>
#include "MainWindow/Ecosystem/Order.hpp"

class EventsGui
{
  enum Column
  {
    TIME,
    ORDER,
    DESCRIPTION
  };
public:
  EventsGui(QTableWidget *table, QSpinBox *successSpin, QSpinBox *canceledSpin);
  void addEvent(double time, Order order, std::string description);
  void addSuccess();
  void addCanceled();

private:
  QTableWidget *table_ = nullptr;
  QSpinBox *successSpin_ = nullptr;
  QSpinBox *canceledSpin_ = nullptr;
  std::unique_ptr< QTableWidgetItem > itemProto_;
};

#endif
