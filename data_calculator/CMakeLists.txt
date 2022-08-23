cmake_minimum_required(VERSION 3.21)
project(cs5008)

set(CMAKE_CXX_STANDARD 14)

add_executable(finalProj main.cpp
        dateType.h dateType.cpp timeType.h timeType.cpp
        airQualityType.h airQualityType.cpp main.h)
