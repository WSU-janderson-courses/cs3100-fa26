cmake_minimum_required(VERSION 3.28)
project(cs3100_solution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(CURRENT_DIR_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
get_filename_component(PARENT_DIR_NAME "${PARENT_DIR}" NAME)

if (CURRENT_DIR_NAME STREQUAL "starter" OR CURRENT_DIR_NAME STREQUAL "solution")
    set(TARGET_NAME "${PARENT_DIR_NAME}_${CURRENT_DIR_NAME}")
else ()
    set(TARGET_NAME "${CURRENT_DIR_NAME}")
endif ()

add_executable(${TARGET_NAME} main.cpp
)

