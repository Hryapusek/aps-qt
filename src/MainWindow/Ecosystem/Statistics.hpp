#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <QObject>
#include <vector>
#include "Order.hpp"

class Statistics : public QObject
{
public:
  Statistics(int nDevices);
  void addSuccessOrder(Order order, double finishTime);
  void addRejected(Order order, double rejectTime);
  void addDeviceProcessingTime(double startTime, double finishTime);
  double getRejectProbability() const;
  double getAvgTimeInSystem() const;
  double getDeviceLoad() const;

private:
  int nSuccess_ = 0;
  int nRejected_ = 0;
  std::vector< double > orderTimesInSystem_;
  double devicesTime_ = 0;
  int nDevices_;
  int lastFinishedOrderTime_ = 0;

  void addAvgTime(const Order &order, double finishTime);
};

#endif
