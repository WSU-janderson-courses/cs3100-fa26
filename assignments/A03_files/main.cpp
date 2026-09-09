/**
 * @file main.cpp
 * @par Assignment
 * A2 - C++ Files
 *
 * @brief This assignment demonstrates separating C++ code across files. In this example we are only
 * using functions declared in a header (.h) and defined in a source (.cpp) but later we will
 * mostly do this when declaring and defining classes
 */
#include <iostream>

// copy and paste the function declarations from dice.h here
#include "dice.h"


int main() {
    // std::cout << roll1;

    int roll1; // declare an int
    int roll2 = roll_d20(); // declare and initialize an int
    roll1 = roll_d6();

    std::cout << "Rolling a d6:  " << roll1 << std::endl;
    std::cout << "Rolling a d20: " << roll_d20() << std::endl;

    return 0;
}


