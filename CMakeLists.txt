cmake_minimum_required(VERSION 3.10)
set(target aps)
project(${target} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${target}
  src/MainWindow/main.cpp

  src/MainWindow/MainWindow.cpp
  src/MainWindow/MainWindow.hpp

  src/MainWindow/StartupDialog.cpp
  src/MainWindow/StartupDialog.hpp

  src/MainWindow/Ecosystem/Buffer.cpp
  src/MainWindow/Ecosystem/DeviceHolder.cpp
  src/MainWindow/Ecosystem/Event.cpp
  src/MainWindow/Ecosystem/EventHolder.cpp
  src/MainWindow/Ecosystem/Order.cpp
)

target_link_libraries(${target} Qt5::Widgets)
