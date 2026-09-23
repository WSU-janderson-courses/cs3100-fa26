/**
 * @file swap.cpp
 * @brief Source file for A3 - Parameters and References
 * 
 * This file demonstrates three different ways to pass variables
 * to a function in C++
 *
 * 1. Pass by value
 * 2. Pass by reference
 * 3. Pass by pointer
 * 
 * Each function tries to swap two integers and prints both the values 
 * and memory addresses so we can see what is actually happening.
 *
 * @author james 
 * @date  6/5/2026
 */

#include "swap.h"
#include <iostream>

/**
 *  This function receives COPIES of the original arguments
 * 
 * If the caller passes in x and y, then a and b are local variables
 * inside this function. Changing a and b does not change x and y.
 */
void swap_by_value(int a, int b)
{
    std::cout << "In swap_by_value(): " << std::endl;

    std::cout << "before swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // These are the addreses of the local copies a and b
    // They will (usually) be different from the addresses
    // of the original variables in main()
    std:: cout << "&a = " << &a << ", &b = " << &b << std::endl;

    // standard swap algorithm using a temporary variable
    int temp = a;
    a = b;
    b = temp;


    std::cout << "after swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // The addresses of a and b did not change
    // The values stored at those addresses changed
    std:: cout << "&a = " << &a << ", &b = " << &b << std::endl;

    // When this function ends, the local copies a and b disappear
    // The original variables in main() are unchanged
}

/**
 * This function receives REFERENCES to the original arguments.
 * 
 * A reference is another name for an existing variable.
 * So if the caller passes in x and y, then a refers to x and b refers to y
 * 
 * Changing a changes x
 * Changing b changes y
 */
void swap_by_ref(int& a, int& b)
{
    std::cout << "In swap_by_ref():" << std::endl;

    std::cout << "before swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // These addresses should match the addresses of x and y
    // in main()
    //
    // That is because a and b are not separate copies.
    // They are references to the original variables.
    std:: cout << "&a = " << &a << ", &b = " << &b << std::endl;

    // This swaps the original variables, not copies of x and y but x and y themselves
    int temp = a;
    a = b;
    b = temp;

    std::cout << "after swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // The addresses are still the same.
    // The values stored in the original variables have changed.
    std:: cout << "&a = " << &a << ", &b = " << &b << std::endl;
}

/**
 * This function receives POINTERS to the original arguments.
 * 
 * A pointer stores an address.
 * So a stores the address of one int, and b stores the address of anotyer int.
 * 
 * To access or change the int at that address, we use *a and *b
 *
 * Assumes a and b are not nullptr
 */
void swap_by_ptr(int* a, int* b)
{
    std::cout << "In swap_by_ptr():" << std::endl;

    std::cout << "before swap:" << std::endl;

    // Print the values stored in the original ints
    // *a means, dereference a, follow the address it is storing and get me what is there
    std::cout << "*a = " << *a << ", *b = " << *b << std::endl;

    // a and b are pointer variables.
    // Printing a and b shows the address they are storing
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // &a and &b are the addresses of the pointer variables themselves
    //
    // This is different than a and b.
    //
    // a  = address of the original int
    // &a = address of the local variable a
    std:: cout << "&a = " << &a << ", &b = " << &b << std::endl;

    // *a means "the int that a points to."
    // *b means "the int that b points to."
    //
    // This swaps the original integers by following the pointers.
    // and changing the values at those addresses
    int temp = *a; 
    *a = *b;
    *b = temp;

    std::cout << "after swap:" << std::endl;

    // The values at the original addresses have changed
    std::cout << "*a = " << *a << ", *b = " << *b << std::endl;

    // The pointer variables still store the same addresses.
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    // The local pointer variables are still in the same places
    std:: cout << "&a = " << &a << ", &b = " << &b << std::endl;
}
