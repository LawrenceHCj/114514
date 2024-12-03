cmake_minimum_required(VERSION 3.0)
project(cv-color)


set(CMAKE_CXX_STANDARD 11)


find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(cv-color main.cpp)


target_link_libraries(cv-color ${OpenCV_LIBS})

