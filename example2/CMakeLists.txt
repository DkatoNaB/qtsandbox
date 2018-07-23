# Specify minimum version fro CMake
cmake_minimum_required(VERSION 3.0)

# Project'name 
project(timeless)

# CXX standard
set(CMAKE_CXX_STANDARD 14)

# locate qt n shit
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# to emit complie commands for json file you complete me n shit
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# linker flags
#set(CMAKE_EXE_LINKER_FLAGS "-v ")
# Set the output folder where your program will be created & bin folder might be needed later on
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#message(${})
# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/src")
# list all cpp files and separates the main file

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp )

add_executable(${PROJECT_NAME} 
  ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# this is here for my comfort only
add_custom_command(TARGET ${PROJECT_NAME}
  PRE_BUILD
  COMMAND bash -c "cp -v ${CMAKE_BINARY_DIR}/compile_commands.json ${PROJECT_SOURCE_DIR}"
  )
