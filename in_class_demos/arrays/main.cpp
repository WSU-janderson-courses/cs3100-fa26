/**
 * @file main.cpp
 * @brief in-class examples of arrays in C++
 */
#include <iostream>

// to pass an array in C++, we need to pass the "array", which is actually
// a pointer to the first element, as well as the number of elements
// C++ has no way for us to know the size of the array just from the pointer
void print_array(const int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
        //array[i] = array[i] * 10; // if we use `const` when passing the array, we can't modify the elements
    }
    std::cout << std::endl;
}

// here we aren't using `const` when passing the array, meaning we can alter what `array` is pointing to...
void fill_range_array(int array[], int array_size, int range_start) {
    for (int i = 0; i < array_size; i++) {
        array[i] = i + range_start; // what happens to the array that is passed in?
    }
}

int main() {
    std::cout << "Array Demos" << std::endl << std::endl;

    // const: we assign it when we declare it, and we can't modify it later
    const int ARRAY_SIZE = 6;

    int num = 42;

    // create an array on the stack that can hold `ARRAY_SIZE` number of ints
    // the `= {}` fills the array with default values
    int array[ARRAY_SIZE] = {}; // raw array

    // assign 1, 2, 3, ... to all elements of array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // update element at index 2
    //'array[2] = num;

    // output array, but `ARRAY_SIZE + 1` accesses off the end of the array
    // C++ does not prevent you from doing this
    // undefined behavior: many things in C++ result in undefined behavior
    // meaning what happens when we do it isn't specified. It could crash the program,
    // give us a random value, seemingly give the "correct" value, and so on
    std::cout << "printing array from index 0 to " << ARRAY_SIZE + 1 << ":" << std::endl;
    for (int i = 0; i < ARRAY_SIZE + 1; i++) {
         std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // call our `print_array` function passing `array` and ARRAY_SIZE
    // we could pass something other than ARRAY_SIZE, like ARRAY_SIZE + 1, and the output will
    // be the same as the previous for loop
    std::cout << "calling print_array(array, ARRAY_SIZE):" << std::endl;
    print_array(array, ARRAY_SIZE);
    std::cout << std::endl;

    // `array` is a pointer to the first element, so this prints the address where the array begins
    std::cout << "array: " << array << std::endl;
    std::cout << std::endl;

    // & means "address of", so this points `ptr` to `num`
    int* ptr = &num;

    // `ptr` is the address where `num` is
    // `*ptr` dereferences the pointer and gets the value stored at the address stored in `ptr`
    std::cout << " ptr: " << ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << std::endl;

    // dereference `ptr`, and put `1000` at that address, which is where num is in memory
    *ptr = 1000;

    // `num` should now be `1000`
    std::cout << "after `*ptr = 1000`:" << std::endl;
    std::cout << " num: " << num << std::endl;
    std::cout << std::endl;

    // because `array` points to the first element of the array, `ptr` now also points to the first element of the array
    ptr = array;

    std::cout << "after `ptr = array`:" << std::endl;
    std::cout << " ptr: " << ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << std::endl;

    // add `2` to pointer, and store `10` at that address
    *(ptr + 2) = 10;
    std::cout << "array after after `*(ptr + 2) = 10:" << std::endl;
    print_array(array, ARRAY_SIZE);
    std::cout << std::endl;

    // this is the same as *(ptr + 2), add `2` to pointer and store `100` at that address
    // this is what we are doing when we work with arrays, and that is why arrays begin at index `0`
    // (array + 0) == array, and *(array + 0) == array[0]
    ptr[2] = 100;
    std::cout << "array after after `ptr[2] = 100:" << std::endl;
    print_array(ptr, ARRAY_SIZE);
    std::cout << std::endl;

    // does this change what is stored in the array?
    fill_range_array(array, ARRAY_SIZE, 100);
    print_array(array, ARRAY_SIZE);
    std::cout << std::endl;

    return 0;
}

