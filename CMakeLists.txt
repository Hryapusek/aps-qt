cmake_minimum_required(VERSION 3.10)
set(target aps)
project(${target} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${target}
  src/MainWindow/main.cpp

  src/MainWindow/MainWindow.cpp
  src/MainWindow/MainWindow.hpp

  src/MainWindow/StartupDialog.cpp
  src/MainWindow/StartupDialog.hpp
)

target_link_libraries(${target} Qt5::Widgets)
