#ifndef EVENT_HOLDER_HPP
#define EVENT_HOLDER_HPP

#include "Event.hpp"
#include "DeviceHolder.hpp"
#include "Buffer.hpp"
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

class EventHolder : public QObject
{
  Q_OBJECT
public:
  EventHolder(const InputParameters &params);
  void step();
  void finalize();
  bool isFinished() const;

private:
  InputParameters params_;
  double eventsInterval_;
  std::unique_ptr<DeviceHolder> deviceHolder_;
  std::unique_ptr<Buffer> buffer_;
  std::set< Event > events_;
  double calcEventsInterval();
  void processEvent(const Event &event);
  void rejectOrder(const Order &order);
  void processOrderCreatedEvent(const Event &event);
  void processDeviceFinishedEvent(const Event &event);
  void printEvents();
};

#endif
