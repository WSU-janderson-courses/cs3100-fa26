/**
 * @file main.cpp
 * @brief in-class examples of dynamically allocating arrays in C++
 */
#include <iostream>


void print_array(const int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void fill_range_array(int array[], int array_size, int range_start) {
    for (int i = 0; i < array_size; i++) {
        array[i] = i + range_start;
    }
}

int main() {
    std::cout << "Dynamic Memory Demos" << std::endl << std::endl;

    const int ARRAY_SIZE = 6;

    int num = 42;

    int array[ARRAY_SIZE] = {};

    fill_range_array(array, ARRAY_SIZE, 100);
    print_array(array, ARRAY_SIZE);


    return 0;
}

