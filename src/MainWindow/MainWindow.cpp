#include "MainWindow.hpp"
#include "UiMainWindow.hpp"
#include "StartupDialog.hpp"

#include <QTimer>
#include <QMessageBox>

#include <ranges>
#include <iostream>

MainWindow::MainWindow() :
  ui_(std::make_unique< Ui::MainWindow >())
{
  ui_->setupUi(this);
  for (const int i: std::ranges::views::iota(0, ui_->splitter->count()))
    ui_->splitter->setCollapsible(i, false);

  #ifdef _NDEBUG
  QTimer::singleShot(0, this, &MainWindow::execStartupWindow);
  #else
  InputParameters params
  {
    .nDevices = 5,
    .nClients = 10,
    .time = 10,
    .bufferSize = 5,
    .minDeviceTime = 1,
    .maxDeviceTime = 2,
    .lambda = 3,
  };
  initParams(params);
  #endif
}

MainWindow::~MainWindow()
{ }

void MainWindow::step()
{
  if (eventHolder_->isFinished())
  {
    ui_->statusLine->setText(QString::fromStdString("Finished"));
    return;
  }
  eventHolder_->step();
  updateStatistics();
  if (eventHolder_->isFinished())
    ui_->statusLine->setText(QString::fromStdString("Finished"));
}

void MainWindow::finish()
{
  if (eventHolder_->isFinished())
  {
    ui_->statusLine->setText(QString::fromStdString("Finished"));
    return;
  }
  while (!eventHolder_->isFinished())
  {
    eventHolder_->step();
    updateStatistics();
  }
  ui_->statusLine->setText(QString::fromStdString("Finished"));
}

void MainWindow::execStartupWindow()
{
  std::unique_ptr< StartupDialog > dialog = std::make_unique< StartupDialog >(this);
  while (true)
  {
    auto res = dialog->exec();
    if (res == QDialog::Rejected)
      QApplication::quit();
    if (dialog->maxDeviceTime() < dialog->minDeviceTime())
    {
      QMessageBox::warning(this, "Bad value", "max device time must be less than min device time");
      continue;
    }
    break;
  }

  InputParameters params
  {
    .nDevices = dialog->devicesCount(),
    .nClients = dialog->clientsCount(),
    .time = dialog->time(),
    .bufferSize = dialog->bufferSize(),
    .minDeviceTime = dialog->minDeviceTime(),
    .maxDeviceTime = dialog->maxDeviceTime(),
    .lambda = dialog->lambda(),
  };
  initParams(params);
}

void MainWindow::updateStatistics()
{
  ui_->calcelProbSpin->setValue(eventHolder_->getRejectProbability());
  ui_->avgTimeSpin->setValue(eventHolder_->getAvgTimeInSystem());
  ui_->deviceLoadSpin->setValue(eventHolder_->getDeviceLoad());
}

void MainWindow::initParams(const InputParameters &params)
{
  eventsGui_ = std::make_unique< EventsGui >(ui_->eventsTable, ui_->successSpin, ui_->calceledSpin);
  bufferGui_ = std::make_unique< BufferGui >(ui_->bufferTable, params.bufferSize);
  devicesGui_ = std::make_unique< DevicesGui >(ui_->devicesTable, params.nDevices);
  clientsGui_ = std::make_unique< ClientsGui >(ui_->clientsTable, params.nClients);
  eventHolder_ = std::make_unique< EventHolder >(params, bufferGui_.get(), devicesGui_.get(), eventsGui_.get(), clientsGui_.get());
  QObject::connect(ui_->stepBtn, &QPushButton::clicked, this, &MainWindow::step);
  QObject::connect(ui_->autoBtn, &QPushButton::clicked, this, &MainWindow::finish);
}
