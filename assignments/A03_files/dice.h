/**
* @file dice.h
* @brief Header file for the *declarations* of `roll_d6()` and `roll_d20()`
*
* @author james 
* @date  12/27/2025.
*/

#ifndef A2_FILES_DICE_H // pre-processor directives: if this macro isn't a thing, then compile the code here
#define A2_FILES_DICE_H // if however A2_FILES_DICE_H has been defined, the compiler will never see the code
                        // that ensures the code will only be compiled once and avoid the functions being declared twice
                        // sometimes this is referred to as a header-guard


// place function declarations here

/**
 * Simulate rolling a D6
 * @return int between 1-6
 */
int roll_d6();

/** Simulate rolling a D20
 * @return int between 1 and 20
 */
int roll_d20();


#endif //A2_FILES_DICE_H
        // this closes the #ifndef from above, any code in between the #ifndef and this #endif will only get complied
        // if the macro A2_FILES_DICE_H is not defined
        // there is also #ifdef which would mean, compile this code only `if` the macro is defined
