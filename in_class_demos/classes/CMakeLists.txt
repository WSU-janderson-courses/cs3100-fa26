cmake_minimum_required(VERSION 3.28)
project(demo_classes)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        IntArrayList.cpp
        IntArrayList.h

)
