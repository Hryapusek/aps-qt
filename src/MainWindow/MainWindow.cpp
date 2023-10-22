#include "MainWindow.hpp"
#include "UiMainWindow.hpp"
#include "StartupDialog.hpp"
#include <QTimer>
#include <ranges>
#include <iostream>

MainWindow::MainWindow() :
  ui_(std::make_unique<Ui::MainWindow>())
{
  ui_->setupUi(this);
  for (const int i: std::ranges::views::iota(0, ui_->splitter->count()))
    ui_->splitter->setCollapsible(i, false);
    
  QTimer::singleShot(0, this, &MainWindow::execStartupWindow);
}

MainWindow::~MainWindow()
{

}

void MainWindow::execStartupWindow()
{
  std::unique_ptr<StartupDialog> dialog = std::make_unique<StartupDialog>(this);
  auto res = dialog->exec();
  if (res == QDialog::Rejected)
    QApplication::quit();
  else
    std::cerr << "Accepted\n";
}
