/**
 * @file functions.h
 * @brief This file contains function declarations, but not their definitions.
 *
 * Including this file in other C++ files will let those files know
 * that these functions exist so they can be called.
 *
 * The definitions/implementations of these functions are located in the
 * source file `functions.cpp`
 *
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// function declarations

/**
 * Returns the value passed with 5 added to it
 * @param value integer to add 5 to
 * @return the value passed in plus 5
 */
int add_five(int value); // pass by value (copy)

/**
 * Calls add_five()` to add five to `num`, and outputs the result
 * @param num integer to output with 5 added to it
 */
void print_plus_five(int num); // pass by value (copy)

/**
 * Increment the value passed. Because value is passed by reference, the
 * original variable passed to increment_value(int&) will be modified
 * and have 1 added to it.
 * @param value reference to an integer, both value and the variable passed
 * will be incremented
 */
void increment_value(int& value); // pass by reference

/**
 * Increments the value pointed to by `ptr`. The address of an integer
 * is passed in, and the integer at that address is incremented.
 * @param value a pointer to an integer, the integer at that address
 * is incremented
 */
void increment_value(int* ptr); // pass by pointer (pointer is copied)
#endif