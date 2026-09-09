/**
 * @file main.cpp
 * @brief in-class examples of arrays in C++
 */
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    // const: we assign it when we declare it, and we can't modify it later
    const int ARRAY_SIZE = 6;

    // create an array on the stack that can hold `ARRAY_SIZE` number of ints
    // the `= {}` fills the array with default values
    int array[ARRAY_SIZE] = {}; // raw array

    // update element at index 0
    array[0] = 42;

    // assign 10, 20, 30, ... to all elements of array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = (i + 1) * 10;
    }

    // output array, but `ARRAY_SIZE + 1` accesses off the end of the array
    // C++ does not prevent you from doing this
    // undefined behavior: many things in C++ result in undefined behavior
    // meaning what happens when we do it isn't specified. It could crash the program,
    // give us a random value, seemingly give the "correct" value, and so on
    for (int i = 0; i < ARRAY_SIZE + 1; i++) {
        std::cout << array[i] << std::endl;
    }


    return 0;
}

