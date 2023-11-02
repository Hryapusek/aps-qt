#ifndef BUFFER_GUI_HPP
#define BUFFER_GUI_HPP

#include <QTableWidget>
#include "MainWindow/Ecosystem/Order.hpp"

class BufferGui
{
  enum Column
  {
    INDEX,
    PUSH,
    ORDER,
    POP
  };
public:
  BufferGui(QTableWidget *table, int bufferSize);
  void push_back(Order order);
  void pop_front();

private:
  QTableWidget *table_ = nullptr;
  int size_ = 0;
  int pushIndex = 0;
  int popIndex = 0;
  int count = 0;
  void movePushCursor();
  void movePopCursor();
};

#endif
