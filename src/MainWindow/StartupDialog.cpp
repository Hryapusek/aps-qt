#include "StartupDialog.hpp"
#include "UiStartupDialog.hpp"

StartupDialog::StartupDialog(QWidget *parent) :
  QDialog(parent),
  ui_(std::make_unique<Ui::StartupDialog>())
{
  ui_->setupUi(this);
}

StartupDialog::~StartupDialog()
{}

int StartupDialog::devicesCount() const
{
  return ui_->devicesSpin->value();
}

int StartupDialog::clientsCount() const
{
  return ui_->clientsSpin->value();
}

int StartupDialog::time() const
{
  return ui_->timeSpin->value();
}

int StartupDialog::bufferSize() const
{
  return ui_->bufferSpin->value();
}

double StartupDialog::minDeviceTime() const
{
  return ui_->minDeviceTimeSpin->value();
}

double StartupDialog::maxDeviceTime() const
{
  return ui_->maxDeviceTimeSpin->value();
}

double StartupDialog::lambda() const
{
  return ui_->lambdaSpin->value();
}
