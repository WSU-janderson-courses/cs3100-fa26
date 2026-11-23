cmake_minimum_required(VERSION 3.28)
project(demo_file_io)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        Record.cpp
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/records.txt
        ${CMAKE_CURRENT_BINARY_DIR}/records.txt COPYONLY)