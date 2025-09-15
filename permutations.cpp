// David Janney

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
        int ran; // random number for permutation 1
        do {
            ran = randint (1, size); // 
        }
        while (search (array, i, ran) < i);
        array[i] = ran;
    }
}

void permutations2 (int array[], size_t size) {
    bool *used = new bool[size](); // new bool from RPA in class materials
    
    for (int i = 0; i < size; i++) { // NOT MODIFIED YET!!!!!!!!
        int ran; // random number for permutation 2
        do {
            ran = randint (1, size); // 
        }
        while (used[ran - 1] == true);
        array[i] = ran;
        used[ran - 1] = true;
    }
    delete[] used; // deletes the array
}

void permutations3 (int array[], size_t size) {
    int k; // for later use as a temporary variable
    
    for (int i = 0; i < size; i++) {
        array[i] = (i + 1); // sets the array to (1, 2,..., n)
    }
    
    for (int i = 0; i < size; i++) {
        int j = randint (1, size);
        k = array[i]; // puts i in k
        array[i] = array[j]; // puts j in i
        array[j] = k; // puts k in j, completing the cycle
    }
}
