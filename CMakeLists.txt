cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD  14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

set(inc_dirs /usr/local/include)


set(link_dirs /usr/local/lib)
set(link_libs pthread)


include_directories(${inc_dirs})
link_directories(${link_dirs})

find_package(Qt5Widgets)

add_executable(QTStopWatch main.cpp
        mainwindow.cpp )

target_link_libraries(QTStopWatch Qt5::Widgets)
