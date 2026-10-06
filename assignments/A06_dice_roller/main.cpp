/**
 * @file main.cpp
 * @brief Coding Assignment - Dice Roller
 * 
 * In this assignment, we implement a dice roller simulator. The user inputs how many dice, the number of sides per
 * die, and how many times to roll the dice. The program then simulates those rolls and counts the
 * frequency of each result. 
 * 
 * For example, if there are 3 4-sided dice, the possible results are: 3, 4, ... , 12.
 * 
 * In `counts_array`, each index stores how many times a result is rolled. So, counts_array[3] is how many times 
 * a total result of `3` was rolled, counts_array[4] is how many times a total result of `4` was rolled, etc.
 * 
 * Because the size of `counts_array` depends on the user input number of dice and number of sides per dice, it 
 * needs to be allocated dynamically while the program is running. 
 * 
 * To allocate an array, we use the `new` keyword.
 * 
 * Because we allocate with `new`, we need to deallocate the array with `delete` before the array goes out-of-scope, 
 * which in this case is when the program terminates.
 * 
 * @date 10/6/2026
 */

#include <iostream>

#include "dice.h"


int main() {
    std::cout << "Welcome to DiceRoller!" << std::endl;

    int num_dice = 0;
    int num_sides = 0;
    int num_rolls = 0;

    std::cout << "Enter the number of dice: ";
    std::cin >> num_dice;

    std::cout << "Enter the number of sides: ";
    std::cin >> num_sides;

    std::cout << "Enter the number of rolls: ";
    std::cin >> num_rolls;

    // we need to be able to access index (num_sides * num_dice), so we need to 
    // allocate one more than that, since arrays are zero indexed and the
    // last valid index is size - 1.
    int* counts_array = new int[(num_sides * num_dice) + 1]{};

    simulate_rolls(num_rolls, num_dice, num_sides, counts_array);
    print_results(counts_array, num_sides, num_dice);

    // since we allocated with square brackets [], delete should use them also
    // that tells the operating system counts_array points to multiple ints, and
    // not just a single int
    delete[] counts_array;

    return 0;
}
