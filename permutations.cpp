// YOUR NAME HERE

#include "permutations.h"
#include "randint.h"
#include <cstddef>

// A sequential search function, for your convenience.
// Parameters:
//  array - The array of int's to be searched
//  size - The size of the array
//  target - The target value
// Returns:
//  Array index where target is found, or size if target is not found.
// Example:
//  if (search(array, size, x) < size)
//      cout << "x was found in the array\n";
//  else
//      cout << "x was not found in the array\n";
static size_t search (const int array[], size_t size, int target) {
    for (size_t i = 0; i < size; i++)
    if (array[i] == target)
        return i;
    return size;
}

void permutations1 (int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        int rand_num1; // random number for permutation 1
        do {
            rand_num1 = randint (1, size); // 
        }
        while (search (array, i, rand_num1) < i);
        array[i] = rand_num1;
    }
}

void permutations2 (int array[], size_t size) {
    // TODO: Implement algorithm #2 here
}

void permutations3 (int array[], size_t size) {
    // TODO: Implement algorithm #3 here
}
