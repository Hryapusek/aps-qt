#include "Statistics.hpp"

#include <numeric>
#include <cassert>
#include <execution>

Statistics::Statistics(int nDevices) :
  nDevices_(nDevices)
{ }

void Statistics::addSuccessOrder(Order order, double finishTime)
{
  nSuccess_++;
  lastFinishedOrderTime_ = finishTime;
  addAvgTime(order, finishTime);
}

void Statistics::addRejected(Order order, double finishTime)
{
  nRejected_++;
  lastFinishedOrderTime_ = finishTime;
  addAvgTime(order, finishTime);
}

void Statistics::addDeviceProcessingTime(double startTime, double finishTime)
{
  assert(startTime <= finishTime);
  devicesTime_ += finishTime - startTime;
}

double Statistics::getRejectProbability() const
{
  return static_cast< double >(nRejected_) / (nRejected_ + nSuccess_);
}

double Statistics::getAvgTimeInSystem() const
{
  return std::reduce(std::execution::par_unseq, orderTimesInSystem_.begin(), orderTimesInSystem_.end(), 0.0) / orderTimesInSystem_.size();
}

double Statistics::getDeviceLoad() const
{
  return devicesTime_ / (lastFinishedOrderTime_ * nDevices_);
}

void Statistics::addAvgTime(const Order &order, double finishTime)
{
  orderTimesInSystem_.push_back(finishTime - order.creationTime());
}
