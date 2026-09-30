/**
* @file counting.cpp
* @brief
*
* @author james 
* @date  9/8/2026.
*/

#include "counting.h"

#include <functional>
#include <iostream>

void count_values(const int data[], int data_size, int counts[]) {
    for (size_t i = 0; i < data_size; i++) {
        counts[data[i]]++;
    }
}

/**
 * When we pass an array, the only thing the function sees is a pointer to
 * the first element. the argument int array[] is the same as saying int* array.
 * We also need to also pass the size of the array, as sizeof now gives us the
 * size of the pointer (usually 8 bytes for a 64-bit address)
 *
 * @param array
 * @param size
 */
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "index: " << i << ": " << array[i] << std::endl;
    }
}

/**
 *  if we want to get fancy, we can specify what to print for each array element
 *  print_func is a callback, or lambda function. The caller passes in what happens
 *  inside that function, and we can have different behavior for different arrays
 *  see examples of using this version of print_array below
 *
 * @param array the array to be printed
 * @param size the number of array elements
 * @param print_func what to print for each value, index pair in the array
 */
void print_array(int array[], int size, std::function<void(int, int)> print_func) {
    for (int i = 0; i < size; i++) {
        print_func(array[i], i);
    }
}