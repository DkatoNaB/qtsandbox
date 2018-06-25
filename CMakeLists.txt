# Specify minimum version fro CMake
cmake_minimum_required(VERSION 3.0)

# Project'name 
project(qtsandbox)

# CXX standard
set(CMAKE_CXX_STANDARD 14)

# locate qt n shit
find_package(Qt5Widgets REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

# later might be useful
#add_library(mainwindow mainwindow.cpp)

# Compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# to emit complie commands for json file you complete me n shit
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# linker flags
#set(CMAKE_EXE_LINKER_FLAGS "-v")
#set(CMAKE_EXE_LINKER_FLAGS "-lstdc++fs -v")
# Set the output folder where your program will be created & bin folder might be needed later on
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(qtsandbox ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries (qtsandbox Qt5::Widgets)

