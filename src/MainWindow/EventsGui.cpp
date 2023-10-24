#include "EventsGui.hpp"


EventsGui::EventsGui(QTableWidget *table, QSpinBox *successSpin, QSpinBox *canceledSpin) :
  table_(table),
  successSpin_(successSpin),
  canceledSpin_(canceledSpin)
{
  itemProto_ = std::make_unique< QTableWidgetItem >(QString());
  itemProto_->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
  itemProto_->setFlags(itemProto_->flags() & ~(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable));
}

void EventsGui::addEvent(double time, Order order, std::string description)
{
  auto newRow = table_->rowCount();
  table_->insertRow(newRow);

  {
    auto timeItem = itemProto_->clone();
    timeItem->setText(QString::fromStdString(std::to_string(time)));
    table_->setItem(newRow, Column::TIME, timeItem);
  }

  {
    auto orderItem = itemProto_->clone();
    orderItem->setText(QString::fromStdString(order.name()));
    table_->setItem(newRow, Column::ORDER, orderItem);
  }

  {
    auto descrItem = itemProto_->clone();
    descrItem->setText(QString::fromStdString(description));
    table_->setItem(newRow, Column::DESCRIPTION, descrItem);
  }
}

void EventsGui::addSuccess()
{
  successSpin_->setValue(successSpin_->value() + 1);
}

void EventsGui::addCanceled()
{
  canceledSpin_->setValue(canceledSpin_->value() + 1);
}
