cmake_minimum_required(VERSION 3.27)
project(PA_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA_2
        Formula.cpp
        Formula.h
        p2.cpp
        Plan.cpp
        Plan.h)
