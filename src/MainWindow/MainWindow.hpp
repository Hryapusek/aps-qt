#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include "Ecosystem/EventHolder.hpp"

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

private:
  std::unique_ptr<Ui::MainWindow> ui_;
  void execStartupWindow();
  std::unique_ptr<EventHolder> eventHolder;
};

#endif
