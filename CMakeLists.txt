cmake_minimum_required(VERSION 3.10)
set(target aps)
project(${target} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_library(Fmt fmt REQUIRED)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${target}
  src/MainWindow/main.cpp

  src/MainWindow/UiMainWindow.hpp

  src/MainWindow/MainWindow.cpp
  src/MainWindow/MainWindow.hpp

  src/MainWindow/StartupDialog.cpp
  src/MainWindow/StartupDialog.hpp

  src/MainWindow/BufferGui.hpp
  src/MainWindow/BufferGui.cpp

  src/MainWindow/DevicesGui.hpp
  src/MainWindow/DevicesGui.cpp

  src/MainWindow/EventsGui.hpp
  src/MainWindow/EventsGui.cpp

  src/MainWindow/Ecosystem/Buffer.hpp
  src/MainWindow/Ecosystem/Buffer.cpp
  
  src/MainWindow/Ecosystem/DeviceHolder.hpp
  src/MainWindow/Ecosystem/DeviceHolder.cpp

  src/MainWindow/Ecosystem/Event.hpp
  src/MainWindow/Ecosystem/Event.cpp

  src/MainWindow/Ecosystem/EventHolder.hpp
  src/MainWindow/Ecosystem/EventHolder.cpp

  src/MainWindow/Ecosystem/Order.hpp
  src/MainWindow/Ecosystem/Order.cpp

  src/MainWindow/Ecosystem/Statistics.hpp
  src/MainWindow/Ecosystem/Statistics.cpp
)

target_link_libraries(${target} Qt5::Widgets ${Fmt})
target_include_directories(${target} PRIVATE ${Qt5Widgets_INCLUDE_DIRS})
target_compile_options(${target} PRIVATE -Wall -Wextra)
