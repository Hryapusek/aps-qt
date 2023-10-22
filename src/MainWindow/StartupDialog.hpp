#ifndef STARTUP_DIALOG_HPP
#define STARTUP_DIALOG_HPP

#include <QDialog>

namespace Ui
{
  class StartupDialog;
}

class StartupDialog : public QDialog
{
  Q_OBJECT

public:
  StartupDialog(QWidget *parent = nullptr);
  ~StartupDialog();
  int devicesCount() const;
  int clientsCount() const;
  int time() const;
  int bufferSize() const;
  double minDeviceTime() const;
  double maxDeviceTime() const;
  double lambda() const;

private:
  std::unique_ptr<Ui::StartupDialog> ui_;
};

#endif
