/**
* @file counting.h
* @brief
*
* @author james 
* @date  9/8/2026.
*/

#ifndef COUNTING_H
#define COUNTING_H

/**
 * Counts occurrences of each value in data.
 *
 * Preconditions:
 * - counts is initialized to zero
 * - counts has enough elements for every possible value in data
 * - all values in data are valid indices into counts
 */
void count_values(const int data[], int data_size, int counts[]);

#endif //COUNTING_H
