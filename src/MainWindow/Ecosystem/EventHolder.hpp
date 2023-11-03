#ifndef EVENT_HOLDER_HPP
#define EVENT_HOLDER_HPP

#include "Event.hpp"
#include "DeviceHolder.hpp"
#include "Buffer.hpp"
#include "Statistics.hpp"
#include "MainWindow/GUI/BufferGui.hpp"
#include "MainWindow/GUI/DevicesGui.hpp"
#include "MainWindow/GUI/EventsGui.hpp"
#include "MainWindow/GUI/ClientsGui.hpp"
#include <set>
#include <memory>
#include <functional>
#include <QObject>

struct InputParameters
{
  int nDevices = 5;
  int nClients = 5;
  int time = 5;
  int bufferSize = 5;
  double minDeviceTime = 0.1;
  double maxDeviceTime = 1;
  double lambda = 0.5;
};

class EventHolder: public QObject
{
  Q_OBJECT
public:
  EventHolder(const InputParameters &params, BufferGui *bufferGui, DevicesGui *devicesGui, EventsGui *eventsGui, ClientsGui *clientsGui);
  void step();
  [[nodiscard]] bool isFinished() const;
  double getRejectProbability() const;
  double getAvgTimeInSystem() const;
  double getDeviceLoad() const;

private:
  InputParameters params_;
  double eventsInterval_;
  std::unique_ptr< DeviceHolder > deviceHolder_;
  std::unique_ptr< Buffer > buffer_;
  std::unique_ptr< Statistics > stats_;
  BufferGui *bufferGui_;
  DevicesGui *devicesGui_;
  EventsGui *eventsGui_;
  ClientsGui *clientsGui_;
  std::set< Event > events_;

  void calcEventsInterval();
  void processEvent(const Event &event);
  void processOrderCreatedEvent(const Event &event);
  void processDeviceFinishedEvent(const Event &event);
  [[nodiscard]] double processOrder(Order order, double time);
  void finishProcessing(Order order, double time);
};

#endif
