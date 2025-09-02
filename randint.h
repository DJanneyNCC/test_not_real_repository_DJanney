/**
 * @file randint.h
 * @brief Convenience functions for random numbers
 * @author N. Lippincott, Northampton Community College
 */

#pragma once

/**
 * Generate a random integer
 *
 * Generates a pseudo-random integer. This function handles
 * seeding of the random number generator, so there is no 
 * need for the calling program to call srand. For operating
 * platforms on which the rand function is limited to 16-bit
 * integers, the range is extended to the 32-bit range.
 *
 * @return Random integer from 0 through RAND_MAX
 */
unsigned int randint();

/**
 * Generates a random integer restricted by a maximum
 *
 * Generates a random integer from 0 through the maximum
 * given minus one. Initialization of the random number
 * generator is handled by this library.
 *
 * @param max Number of possible return values
 * @return Random integer from 0 through max-1
 */
unsigned int randint(unsigned int max);

/**
 * Generates a random integer within the given range
 *
 * Generates a random integer from min through max
 * inclusive. Initialization of the random number
 * generator is handled by this library.
 *
 * @param min Minimum value of return range
 * @param max Maximum value of return range
 * @return Random integer from min ghrough max
 */
unsigned int randint(unsigned int min, unsigned int max);
