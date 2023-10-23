#include "DeviceHolder.hpp"

#include <ranges>
#include <algorithm>
#include <random>
#include <utility>

DeviceHolder::DeviceHolder(int nDevices, double minProcessingTime, double maxProcessingTime)
{
  for (const auto deviceId : std::ranges::views::iota(0, nDevices))
  {
    devices_.insert({ deviceId, Device(deviceId, minProcessingTime, maxProcessingTime) });
  }
}

double DeviceHolder::processOrder(Order order, double time)
{
  for (auto &device : devices_ | std::views::values)
  {
    if (device.isFree(time))
    {
      auto finishTime = device.processOrder(order, time);
      return finishTime;
    }
  }
  throw std::exception();
  std::unreachable();
}

bool DeviceHolder::hasSpace(double time)
{
  using namespace std::ranges;
  return std::ranges::any_of(
    devices_ | views::values,
    [time](const Device &d) {
    return d.isFree(time);
  });
}

DeviceHolder::Device::Device(int id, double minProcessingTime, double maxProcessingTime) :
  id_(id),
  minTime_(minProcessingTime),
  maxTime_(maxProcessingTime)
{ }

bool DeviceHolder::Device::isFree(double time) const noexcept
{
  return !order_ || finishTime_ <= time;
}

double DeviceHolder::Device::processOrder(Order order, double startTime)
{
  order_ = order;
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_real_distribution< double > distribution(minTime_, maxTime_);
  finishTime_ = startTime + distribution(engine);
  return finishTime_;
}
