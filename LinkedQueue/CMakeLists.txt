cmake_minimum_required(VERSION 3.25)
project(queLL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        queLL
        QueType.h problem02.cpp)
