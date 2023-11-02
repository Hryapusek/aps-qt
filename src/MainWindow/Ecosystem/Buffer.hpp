#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "Order.hpp"

#include <QObject>
#include <boost/circular_buffer.hpp>
#include "MainWindow/GUI/BufferGui.hpp"
#include "MainWindow/GUI/EventsGui.hpp"
#include "Statistics.hpp"

class Buffer : public QObject
{
  Q_OBJECT

public:
  Buffer(int bufferSize, BufferGui *bufferGui, EventsGui *eventsGui);
  /// @param time used only for statistics
  void addOrder(Order order, double time);
  void popOrder(double time);
  /// @param time used only for statistics
  [[nodiscard]] const Order &nextOrder();
  [[nodiscard]] bool hasSpace() const noexcept;
  [[nodiscard]] bool empty() const noexcept;

signals:
  void orderRejected(Order order, double rejectTime);

private:
  boost::circular_buffer<Order> queue_;
  BufferGui *bufferGui_;
  EventsGui *eventsGui_;
};

#endif
