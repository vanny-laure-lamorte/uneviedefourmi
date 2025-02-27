cmake_minimum_required(VERSION 3.10)
project(UNEVIEDEFOURMI)

find_package(Python3 REQUIRED COMPONENTS Development NumPy)
if (NOT Python3_FOUND)
    message(FATAL_ERROR "Python3 not found!")
    find_package(Python3 COMPONENTS Interpreter NumPy REQUIRED)
else()
    message(STATUS "Python3 found: ${Python3_VERSION}")
    message(STATUS "Python3 include directories: ${Python3_INCLUDE_DIRS}")
    message(STATUS "Python3 libraries: ${Python3_LIBRARIES}")
    message(STATUS "Python3 NumPy include directories: ${Python3_NumPy_INCLUDE_DIRS}")
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
)

file(GLOB SRC_FILES src/core/*.cpp src/io/*.cpp src/ui/*.cpp src/config/*.cpp src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES}
                Main.cpp)
message(STATUS "SRC_FILES: ${SRC_FILES}")



target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})