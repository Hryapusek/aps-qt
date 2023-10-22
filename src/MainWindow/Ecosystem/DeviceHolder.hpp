#ifndef DEVICE_HOLDER_HPP
#define DEVICE_HOLDER_HPP

class DeviceHolder
{
public:
  DeviceHolder(int nDevices);
  /// @return time when processing will finish
  double processOrder(Order order, double time);
  bool hasSpace(double time);
};

#endif
