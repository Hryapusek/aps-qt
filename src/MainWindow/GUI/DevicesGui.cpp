#include "DevicesGui.hpp"

#include <ranges>

DevicesGui::Device::Device(int index) :
  index_(index)
{}

void DevicesGui::Device::processOrder(Order order)
{
  order_ = std::make_unique< Order >(std::move(order));
  isFree_ = false;
}

void DevicesGui::Device::finishProcessing()
{
  isFree_ = true;
}

constexpr bool DevicesGui::Device::isFree() const noexcept
{
  return isFree_;
}

constexpr int DevicesGui::Device::index() const noexcept
{
  return index_;
}

constexpr bool DevicesGui::Device::operator==(const Order &order) const noexcept
{
  return !isFree_ && *this->order_ == order;
}

constexpr DevicesGui::Device::operator bool() const noexcept
{
  return isFree_;
}

DevicesGui::DevicesGui(QTableWidget *table, int nDevices) :
  table_(table)
{
  itemProto_ = std::make_unique< QTableWidgetItem >(QString());
  itemProto_->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
  itemProto_->setFlags(itemProto_->flags() & ~(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable));
  for (auto index : std::ranges::views::iota(0, nDevices))
  {
    devices_.push_back(Device(index));
    auto newRow = table_->rowCount();
    table_->insertRow(newRow);

    {
      auto indexText = QString::fromStdString(std::to_string(newRow));
      auto indexItem = itemProto_->clone();
      indexItem->setText(indexText);
      table_->setItem(newRow, Column::INDEX, indexItem);
    }

    table_->setItem(newRow, Column::ORDER, itemProto_->clone());

    table_->setVerticalHeaderItem(newRow, new QTableWidgetItem(""));
  }
}

void DevicesGui::process(Order order)
{
  auto isDeviceFree = [](const Device &d) {
    return d.isFree();
  };
  auto device = std::ranges::find_if(devices_, isDeviceFree);
  if (device == devices_.end()) [[unlikely]]
    throw std::logic_error("No free devices\n");
  device->processOrder(order);
  auto orderItem = itemProto_->clone();
  orderItem->setText(QString::fromStdString(order.name()));
  table_->setItem(device->index(), Column::ORDER, orderItem);
}

void DevicesGui::finishProcessing(Order order)
{
  auto device = std::find(devices_.begin(), devices_.end(), order);
  assert(device != devices_.end());
  device->finishProcessing();
  table_->setItem(device->index(), Column::ORDER, itemProto_->clone());
}
