/**
 * @file main.cpp
 * @brief Coding Assignment - Arrays and Counting
 *
 *  In this assignment, we need to declare an array, initializing it with zeros. Then we loop through a `data` array and
 *  count how many occurrences of each values. Then we print the results.
 *
 *  @author james
 */
#include <iostream>
#include <functional>

#include "counting.h"

void print_array(int array[], int size);
void print_array(int array[], int size, std::function<void(int, int)> print_func);

int main() {
    int data[] = {2, 1, 3, 2, 0, 4, 1, 2, 3, 0}; // data contains values 0 - 4
    const int DATA_SIZE = 10; // data contains 10 values

    // Print out the `data` array
    //print_array(data, DATA_SIZE);
    print_array(data, DATA_SIZE, [](int value, int index) {
        // this is the code for print_func
        // for every element of the array data, this code will run
        std::cout << value;
        // knowing which index the value is at, we can print a comma after everything that isn't the last element
        // so this should print the array like:
        // 2, 1, 3, 2, 0, 4, 1, 2, 3, 0
        if (index < DATA_SIZE - 1) {
            std::cout << ", ";
        }
    });
    std::cout << std::endl;

    // Declare and initialize a counting array
    const int NUM_VALUES = 5;
    int counts[NUM_VALUES] = {};

    for (int i = 0; i < NUM_VALUES; i++) {
        counts[i] = 0;
    }

    // Loop over data and count occurrences
    count_values(data, DATA_SIZE, counts);

    // Print results
    //std::cout << counts << std::endl;
    std::cout << sizeof(counts) << std::endl;
    std::cout << sizeof(counts) / sizeof(int) << std::endl;

    //print_array(counts, NUM_VALUES);
    print_array(counts, NUM_VALUES, [](int value, int index) {
        // this lambda prints the array as
        // index: i: array[i]
        std::cout << "value: " << index << " count: " << value << std::endl;
    });

    return 0;
}
