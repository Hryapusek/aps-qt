#ifndef EVENT_HOLDER_HPP
#define EVENT_HOLDER_HPP

#include "Event.hpp"
#include "DeviceHolder.hpp"
#include "Buffer.hpp"
#include "../BufferGui.hpp"
#include "../DevicesGui.hpp"
#include "../EventsGui.hpp"
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
  EventHolder(const InputParameters &params, BufferGui *bufferGui, DevicesGui *devicesGui, EventsGui *eventsGui);
  void step();
  [[nodiscard]] bool isFinished() const;

private:
  InputParameters params_;
  double eventsInterval_;
  std::unique_ptr< DeviceHolder > deviceHolder_;
  std::unique_ptr< Buffer > buffer_;
  BufferGui *bufferGui_;
  DevicesGui *devicesGui_;
  EventsGui *eventsGui_;
  std::set< Event > events_;

  [[nodiscard]] double calcEventsInterval();
  void processEvent(const Event &event);
  void processOrderCreatedEvent(const Event &event);
  void processDeviceFinishedEvent(const Event &event);
  double processOrder(Order order, double time);
  void finishProcessing(Order order, double time);
};

#endif
