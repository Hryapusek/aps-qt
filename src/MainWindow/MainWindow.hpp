#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include "Ecosystem/EventHolder.hpp"
#include "GUI/BufferGui.hpp"
#include "GUI/DevicesGui.hpp"
#include "GUI/EventsGui.hpp"
#include "GUI/ClientsGui.hpp"

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

private slots:
  void step();
  void finish();

private:
  std::unique_ptr<Ui::MainWindow> ui_;
  std::unique_ptr<EventHolder> eventHolder_;
  std::unique_ptr<BufferGui> bufferGui_;
  std::unique_ptr<DevicesGui> devicesGui_;
  std::unique_ptr<EventsGui> eventsGui_;
  std::unique_ptr<ClientsGui> clientsGui_;
  void execStartupWindow();
  void updateStatistics();
  void initParams(const InputParameters &params);
};

#endif
