/**
* @file dice_roller.h
* @brief Header file for dice_roller functions.
*
* @author james
* @date  9/15/2026.
*/

#ifndef CS3100DATASTRUCTS_DICE_ROLLER_H
#define CS3100DATASTRUCTS_DICE_ROLLER_H

int roll_die(int sides);

void simulate_rolls(int rolls, int dice, int sides, int counts[]);

void print_results(const int counts[], int sides, int dice);

#endif //CS3100DATASTRUCTS_DICE_ROLLER_H
