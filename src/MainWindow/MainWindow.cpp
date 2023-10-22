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

  QTimer::singleShot(0, this, &MainWindow::execStartupWindow);
}

MainWindow::~MainWindow()
{ }

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

  InputParameters params{
    .nDevices = dialog->devicesCount(),
    .nClients = dialog->clientsCount(),
    .time = dialog->time(),
    .bufferSize = dialog->bufferSize(),
    .minDeviceTime = dialog->minDeviceTime(),
    .maxDeviceTime = dialog->maxDeviceTime(),
    .lambda = dialog->lambda(),
  };

  eventHolder = std::make_unique<EventHolder>(params);
}
