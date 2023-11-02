#ifndef DEVICES_GUI_HPP
#define DEVICES_GUI_HPP

#include <QTableWidget>
#include <memory>
#include "MainWindow/Ecosystem/Order.hpp"

class DevicesGui
{
  struct Device
  {
    Device(int index);
    void processOrder(Order order);
    void finishProcessing();
    constexpr bool isFree() const noexcept;
    constexpr int index() const noexcept;
    constexpr bool operator==(const Order &order) const noexcept;
    /// @return True if device is free. False otherwise
    constexpr operator bool() const noexcept;
  private:
    int index_;
    bool isFree_ = true;
    std::unique_ptr< Order > order_ = nullptr;
  };

  enum Column
  {
    INDEX,
    ORDER,
  };
public:
  DevicesGui(QTableWidget *table, int nDevices);
  void process(Order order);
  void finishProcessing(Order order);

private:
  QTableWidget *table_ = nullptr;
  std::vector< Device > devices_;
  std::unique_ptr< QTableWidgetItem > itemProto_;
};

#endif
