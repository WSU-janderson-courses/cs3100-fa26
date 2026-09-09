/**
* @file dice.cpp
* @brief Source file for the *definitions* of `roll_d6()` and `roll_d20()`
*
* @author james 
* @date  12/27/2025.
*/

#include "dice.h"

// function definitions
int roll_d6() {
    // as an example of why we would want to #include "dice.h", if we didn't,
    // roll_d6() would have to be *after* roll_d20() in order to call roll_d20()

    int result = roll_d20() % 7;
    return result;
}

int roll_d20() {
    return 12;
}