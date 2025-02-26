cmake_minimum_required(VERSION 3.10)
project(UNEVIEDEFOURMI)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB SRC_FILES src/core/*.cpp src/io/*.cpp src/ui/*.cpp src/config/*.cpp src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES}
                Main.cpp)
message(STATUS "SRC_FILES: ${SRC_FILES}")

