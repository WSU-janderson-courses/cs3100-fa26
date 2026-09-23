/**
* @file main.cpp
* @brief Main driver testing the three different swap functions
*
* @author james
* @date  12/28/2025.
*/

#include <iostream>
#include "swap.h"

int main() {
    int x = 5;
    int y = 10;

    std::cout << "in main(): " << x << std::endl;
    std::cout << "&x = " << &x << ", &y = " << &y << std::endl;

    std::cout << "Before swap:\n";
    std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

    swap_by_value(x, y);
    std::cout << "\nAfter swap_by_value:\n";
    std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

    swap_by_ref(x, y);
    std::cout << "\nAfter swap_by_ref:\n";
    std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

    swap_by_ptr(&x, &y);
    std::cout << "\nAfter swap_by_ptr:\n";
    std::cout << "x = " << x << ", y = " << y << std::endl;

    // swap_by_ptr doesn't handle the case of us passing a null pointer
    // so this would crash the program
    //swap_by_ptr(nullptr, nullptr);

    // references cannot be null, they can't be a literal, they have
    // to be a variable that is in memory. A reference references something
    // in memory, and if it's not in memory, you can't pass it as a reference
    //swap_by_ref(2, nullptr);

    std::cout << "&x = " << &x << ", &y = " << &y << std::endl;

    return 0;
}
