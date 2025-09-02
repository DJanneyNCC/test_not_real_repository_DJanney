#include "permutations.h"
#include "timer.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    // Initialize the RNG.
    srand(time(0));

    // Set precision for timer output.
    cout << fixed << setprecision(2);

    // Get input values, algorithm and array size, from command line if
    // provided else from stdin.
    int algo = 0;
    size_t size = 0;
    if (argc == 3) {
        algo = atoi(argv[1]);
        size = atoi(argv[2]);
    }
    else {
        // Prompt for and input algorithm.
        cout << "Enter algorithm (1, 2, or 3): ";
        cin >> algo;
        // Prompt for and input array size.
        cout << "Enter array size: ";
        cin >> size;
        cout << "\n";
    }

    // Validate input values.
    if (algo < 1 || algo > 3) {
        cerr << "Algorithm must be 1, 2, or 3.\n";
        exit(1);
    }
    if (!size) {
        cerr << "Array size must be a positive integer.\n";
        exit(1);
    }

    // Create the array and initialize with zeros.
    int *array = new int[size];
    for (size_t i = 0; i < size; i++)
        array[i] = 0;

    // Call the selected algorithm to fill array with values.
    Timer timer;
    switch (algo) {
        case 1: permutations1(array, size); break;
        case 2: permutations2(array, size); break;
        case 3: permutations3(array, size); break;
    }

    // Report the executation time.
    double execution_time = timer.seconds();
    cout << "Algorithm " << algo << " completed in " << execution_time << " seconds.\n";

    // Verify that every entry in array is a value from 1 through
    // size, and that each value from 1 through size occurs in
    // the array only once.
    bool *used = new bool[size];
    for (size_t i = 0; i < size; i++)
        used[i] = false;
    bool valid = true;
    for (size_t i = 0; i < size; i++) {
        if ((valid = valid && array[i] > 0 && array[i] <= size && !used[array[i] - 1]))
            used[array[i] - 1] = true;
    }
    delete [] used;

    // Display values in array if 20 or under
    if (size <= 20) {
        cout << "Values found in array:";
        for (size_t i = 0; i < size; i++)
            cout << ' ' << array[i];
        cout << "\n";
    }

    // Recover memory allocated to the array
    delete [] array;

    // Display success/failure message
    cout << "Values in the array are " << (valid ? "as expected" : "NOT AS EXPECTED") << ".\n";
}
