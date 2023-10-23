#ifndef DEVICE_HOLDER_HPP
#define DEVICE_HOLDER_HPP

#include "Order.hpp"
#include <map>
#include <optional>

class DeviceHolder
{
  struct Device
  {
    Device(int id, double minProcessingTime, double maxProcessingTime);

    bool isFree(double time) const noexcept;

    /// @return Finish time
    double processOrder(Order order, double startTime);

  private:
    int id_;
    std::optional< Order > order_ = { };
    double finishTime_ = 0;
    double minTime_;
    double maxTime_;
  };

public:
  DeviceHolder(int nDevices, double minProcessingTime, double maxProcessingTime);
  /// @return Time when processing will be finished
  double processOrder(Order order, double time);
  bool hasSpace(double time);

private:
  std::map<int, Device > devices_;
};

#endif
