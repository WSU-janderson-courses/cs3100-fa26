/**
* @file dice_roller.cpp
* @brief Function definitions for dice roller.
*
* @author james 
* @date  9/15/2026.
*/

#include "dice.h"

#include <iostream>
#include <random>

/**
 * roll_die returns a uniform random number from 1 to sides, inclusive
 *
 * @param sides number of sides on the simulated die
 * @return result of rolling a die with given number of sides
 */
int roll_die(int sides) {
   static std::random_device rd;
   static std::mt19937 gen(rd());

   std::uniform_int_distribution<int> distribution(1, sides);

   return distribution(gen);
}

/**
 * Simulate `rolls` number of dice rolls with each roll containing `dice` number of dice with the same number of `sides`.
 * The number of times each resulting dice roll occurs is stored in `counts[]`. For instance, if there were 4 dice,
 *
 * counts[4] = how many times 1, 1, 1, 1 was rolled
 * counts[5] = how many times any combination of 1, 1, 1, 2 was rolled
 * counts[sides * dice] = how many times each die rolled the largest number on the die
 *
 * @param rolls how many die rolls to simulate
 * @param dice how many dice to roll for each total
 * @param sides the number of sides on each dice, so the dice have the numbers 1 to sides
 * @param counts array where the frequency each result occurred during the simulation
 */
void simulate_rolls(int rolls, int dice, int sides, int counts[]) {
   for (int i = 0; i < rolls; i++) { // loop through all the rolls
      int total = 0;

      for (int d = 0; d < dice; d++) { // role how many dice with a loop, and sum each roll
         total += roll_die(sides);
      }

      counts[total]++; // add one to the outcome for this die roll
   }
}

/**
 * Print the results of the dice roll simulation
 *
 * @param counts array containing the results of the simulation
 * @param sides the number of sides on each die
 * @param dice the number of dice rolled for each result
 */
void print_results(const int counts[], int sides, int dice) {
   for (int total = dice; total <= (sides * dice); total++) {
      std::cout << total << ": " << counts[total] << std::endl;
   }
}