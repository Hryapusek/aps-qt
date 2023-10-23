#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include "Ecosystem/EventHolder.hpp"
#include "BufferGui.hpp"

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
  std::unique_ptr<EventHolder> eventHolder_;
  std::unique_ptr<BufferGui> bufferGui_;
  void execStartupWindow();
};

#endif
