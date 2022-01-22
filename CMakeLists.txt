cmake_minimum_required(VERSION 3.20)
project(point)

set(CMAKE_CXX_STANDARD 20)

add_executable(point main.cpp Point.cpp Point.h Utilities.cpp Utilities.h)
