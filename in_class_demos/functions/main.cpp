/**
 * @file main.cpp
 * @brief This file contains the entry point for the program. We include `functions.h` so this file
 * knows about the functions declared in that file. We can then call those functions, even though
 * main.cpp doesn't know anything about their implementation. We can do this because in
 * `CMakeLists.txt` we told cmake that our program needs `main.cpp`, `functions.cpp`, and `functions.h`
 */
#include <iostream>

#include "functions.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::endl;

    int num; // we should initialize num before using it, because there's no guarantee what it's value will be before that
    std::cout << "before initializing num: " << num << std::endl;

    num = 9; // now we know for sure what num is

    std::cout << std::endl;

    int num_result = add_five(num);

    std::cout << "num_result: " << num_result << std::endl;

    print_plus_five(num);

    std::cout << std::endl;

    // up until now, `num` has not been modified since initially setting it
    // because `num` is passed by reference into `increment_value()`, and because `increment_value()` adds one to that
    // reference, after this function call, num will be modified
    std::cout << "before calling increment_value(int&): " << num << std::endl;
    increment_value(num);
    std::cout << "after calling increment_value(int&): " << num << std::endl;

    std::cout << std::endl;

    // another way to let a function modify a variable is to pass a pointer to the variable
    // a pointer is a variable that stores a memory address
    // address-of operator (&): get the address where a variable is stored in memory
    std::cout << "before calling increment_value(int*): " << num << std::endl;
    increment_value(&num);
    std::cout << "after calling increment_value(int*): " << num << std::endl;

    return 0;
}

