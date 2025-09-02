#include "randint.h"
#include <ctime>
#include <cstdlib>

// randInt - Generates a random integer, three versions:
//	- Random integer (with RNG initialization)
//	- Random integer from 1 through max inclusive
//	- Random integer from min through max inclusive
unsigned int randint() {
    static bool initialized = false; // Is RNG initialized?
    if (!initialized) {
        srand(unsigned(int(time(NULL))));
        initialized = true;
    }
#if RAND_MAX == 32767
	return rand() * rand();
#else
	return rand();
#endif
}

unsigned int randint(unsigned int max) { return randint() % max; }

unsigned int randint(unsigned int min, unsigned int max) {
    return min <= max ? randint(max - min + 1) + min : randint(max, min);
}
