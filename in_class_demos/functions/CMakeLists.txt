cmake_minimum_required(VERSION 3.28)
project(demo_functions)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo_functions
        main.cpp
        functions.cpp
        functions.h
)
