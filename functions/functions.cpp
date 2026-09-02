/**
 * @file functions.cpp
 * @brief This file contains the definitions for the functions that are declared
 * in `functions.h`.
 *
 * This file **should not** be included in another source file. Only .h header
 * files are included.
 */
#include <iostream>

#include "functions.h"

// function definitions

// print num plus five
void print_plus_five(int num) {
    std::cout << num << " plus five is " << add_five(num) << std::endl;
}

// return value plus five
int add_five(int value) {
    value = value + 5; // we could also just return value + 5
    return value;
}

// value is a reference to an int, so the int that gets passed in is incremented
void increment_value(int& value) {
    std::cout << "in increment_value(int&): " << value << std::endl;
    ++value; // because value is a reference, this modifies the original variable
    std::cout << "in increment_value(int&): " << value << std::endl;
}

// ptr is the memory address of an integer, and the int at that address gets incremented
void increment_value(int* ptr) {
    std::cout << "in increment_value(int*),  ptr: " << ptr << std::endl; // address
    std::cout << "in increment_value(int*), *ptr: " << *ptr << std::endl; // use dereference operator (*) to follow address in
                                                                    // memory and retrieve the value stored there
    // this line of code does several things
    // the order of operations is:
    // 1. *ptr: follow address stored in ptr and retrieve what is in memory at that address
    // 2. *ptr + 1: now add one to that value that we retrieved
    // 3. *ptr = *ptr + 1: follow where ptr is pointing to again, this time, store the result of the addition at that address
    // these steps follow the order of operations for an assignment:
        // 1. compute the rhs
        // 2. store result in the lhs
    *ptr = *ptr + 1;
}