#ifndef EVENT_HOLDER_HPP
#define EVENT_HOLDER_HPP

#include "Event.hpp"
#include "DeviceHolder.hpp"
#include <set>
#include <memory>
#include <functional>

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

class EventHolder
{
public:
  EventHolder(const InputParameters &params);
  void step();
  void finalize();
  bool isFinished() const;

private:
  InputParameters params_;
  double eventsInterval_;
  std::unique_ptr<DeviceHolder> deviceHolder;
  std::unique_ptr< std::set< Event, std::function<bool(const Event &lhs, const Event &rhs)> > > events_;
  double calcEventsInterval();
  void processEvent(const Event &event);
  void processOrderCreatedEvent(const Event &event);
  void processDeviceFinishedEvent(const Event &event);
};

#endif
