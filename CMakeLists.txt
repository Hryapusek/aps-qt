cmake_minimum_required(VERSION 3.10)
set(target aps)
project(${target} LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED)

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

  src/MainWindow/GUI/BufferGui.hpp
  src/MainWindow/GUI/BufferGui.cpp

  src/MainWindow/GUI/DevicesGui.hpp
  src/MainWindow/GUI/DevicesGui.cpp

  src/MainWindow/GUI/ClientsGui.hpp
  src/MainWindow/GUI/ClientsGui.cpp

  src/MainWindow/GUI/EventsGui.hpp
  src/MainWindow/GUI/EventsGui.cpp

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

target_link_libraries(${target} Qt${QT_VERSION_MAJOR}::Widgets ${Fmt})
target_include_directories(${target} PRIVATE src ${Boost_INCLUDE_DIRS})
target_compile_options(${target} PRIVATE -Wall -Wextra)
target_compile_definitions(${target} PRIVATE _NDEBUG)
