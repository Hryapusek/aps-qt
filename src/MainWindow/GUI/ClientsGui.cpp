#include "ClientsGui.hpp"
#include <ranges>
#include <fmt/format.h>

ClientsGui::ClientsGui(QTableWidget *table, int nClients) :
  table_(table)
{
  itemProto_ = std::make_unique< QTableWidgetItem >(QString());
  itemProto_->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
  itemProto_->setFlags(itemProto_->flags() & ~(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable));
  for (auto index : std::ranges::views::iota(0, nClients))
  {
    auto newRow = table_->rowCount();
    table_->insertRow(newRow);

    {
      auto indexText = QString::fromStdString(fmt::format("{}", index));
      auto indexItem = itemProto_->clone();
      indexItem->setText(indexText);
      table_->setItem(newRow, Column::INDEX, indexItem);
    }

    table_->setVerticalHeaderItem(newRow, new QTableWidgetItem(""));

    table_->setItem(newRow, Column::TIME, itemProto_->clone());
    table_->setItem(newRow, Column::ORDER_NAME, itemProto_->clone());
  }
}

void ClientsGui::update(Order order)
{
  {
    auto timeItem = itemProto_->clone();
    timeItem->setText(QString::fromStdString(std::to_string(order.creationTime())));
    table_->setItem(order.clientId(), Column::TIME, timeItem);
  }

  auto orderItem = itemProto_->clone();
  orderItem->setText(QString::fromStdString(order.name()));
  table_->setItem(order.clientId(), Column::ORDER_NAME, orderItem);
}
