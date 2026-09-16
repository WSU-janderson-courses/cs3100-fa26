/**
 * @file main.cpp
 * @brief in-class examples of dynamically allocating arrays in C++
 */
#include <iostream>

/**
 *
 * @param array
 * @param array_size
 */
void print_array(const int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/**
 *
 * @param array
 * @param array_size
 * @param range_start
 */
void fill_range_array(int array[], int array_size, int range_start) {
    for (int i = 0; i < array_size; i++) {
        array[i] = i + range_start;
    }
}


/**
 * Example function of using `new` to allocate memory, and before the pointer to that
 * memory leaves scope, using `delete` to release that memory
 *
 * @param array_size how many ints the array can hold
 */
void print_new_array(size_t array_size) {
    int* array = new int[array_size];
    fill_range_array(array, array_size, 73);
    print_array(array, array_size);

    delete[] array; // because we allocated the array using `new` we need to deallocate the array with `delete`
}

int main() {
    std::cout << "Dynamic Memory Demos" << std::endl << std::endl;

    const size_t ARRAY_SIZE = 6;
    size_t num = 0;

    int array[ARRAY_SIZE] = {};

    fill_range_array(array, ARRAY_SIZE, 100);
    print_array(array, ARRAY_SIZE);

    std::cout << "Enter the array size: ";
    std::cin >> num;

    int* dynamic_array = new int[num]; // new: allocate memory on the heap and return a pointer
    fill_range_array(dynamic_array, num, 7);
    print_array(dynamic_array, num);

    print_new_array(num);

    delete[] dynamic_array;

    return 0;
}

