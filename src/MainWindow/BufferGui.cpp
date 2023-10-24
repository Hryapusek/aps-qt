#include "BufferGui.hpp"
#include <ranges>
#include <fmt/format.h>

BufferGui::BufferGui(QTableWidget *table, int bufferSize) :
  table_(table),
  size_(bufferSize)
{
  auto itemProto = std::make_unique< QTableWidgetItem >(QString());
  itemProto->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
  itemProto->setFlags(itemProto->flags() & ~(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable));
  for (auto index : std::ranges::views::iota(0, size_))
  {
    auto newRow = table_->rowCount();
    table_->insertRow(newRow);

    {
      auto indexText = QString::fromStdString(fmt::format("{}", newRow));
      auto indexItem = itemProto->clone();
      indexItem->setText(indexText);
      table_->setItem(newRow, Column::INDEX, indexItem);
    }

    table_->setVerticalHeaderItem(newRow, new QTableWidgetItem(""));

    auto boldFont = itemProto->font();
    boldFont.setBold(true);
    boldFont.setPointSize(14);

    {
      auto pushItem = itemProto->clone();
      if (index == 0)
        pushItem->setText(QString::fromStdString("---->"));
      pushItem->setFont(boldFont);
      table_->setItem(newRow, Column::PUSH, pushItem);
    }

    table_->setItem(newRow, Column::ORDER, itemProto->clone());

    {
      auto popItem = itemProto->clone();
      if (index == 0)
        popItem->setText(QString::fromStdString("<----"));
      popItem->setFont(boldFont);
      table_->setItem(newRow, Column::POP, popItem);
    }
  }
}

void BufferGui::push_back(Order order)
{
  auto orderItem = new QTableWidgetItem(QString());
  orderItem->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
  orderItem->setFlags(orderItem->flags() & ~(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable));
  orderItem->setText(QString::fromStdString(order.name()));
  table_->setItem(pushIndex, Column::ORDER, orderItem);
  pushIndex = (pushIndex + 1) % size_;
  movePushCursor();
}

void BufferGui::pop_front()
{
  auto emptyItem = new QTableWidgetItem(QString());
  emptyItem->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
  emptyItem->setFlags(emptyItem->flags() & ~(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable));
  emptyItem->setText(QString::fromStdString(""));
  table_->setItem(popIndex, Column::ORDER, emptyItem);
  popIndex = (popIndex + 1) % size_;
  movePopCursor();
}

void BufferGui::movePushCursor()
{
  if (pushIndex == 0)
  {
    auto prevPushItem = table_->takeItem(size_ - 1, Column::PUSH);
    auto nextPushItem = table_->takeItem(0, Column::PUSH);
    table_->setItem(size_ - 1, Column::PUSH, nextPushItem);
    table_->setItem(0, Column::PUSH, prevPushItem);
  }
  else
  {
    auto prevPushItem = table_->takeItem(pushIndex - 1, Column::PUSH);
    auto nextPushItem = table_->takeItem(pushIndex, Column::PUSH);
    table_->setItem(pushIndex - 1, Column::PUSH, nextPushItem);
    table_->setItem(pushIndex, Column::PUSH, prevPushItem);
  }
}

void BufferGui::movePopCursor()
{
  if (popIndex == 0)
  {
    auto prevPushItem = table_->takeItem(size_ - 1, Column::POP);
    auto nextPushItem = table_->takeItem(0, Column::POP);
    table_->setItem(popIndex - 1, Column::POP, nextPushItem);
    table_->setItem(popIndex, Column::POP, prevPushItem);
  }
  else
  {
    auto prevPushItem = table_->takeItem(popIndex - 1, Column::POP);
    auto nextPushItem = table_->takeItem(popIndex, Column::POP);
    table_->setItem(popIndex - 1, Column::POP, nextPushItem);
    table_->setItem(popIndex, Column::POP, prevPushItem);
  }
}
