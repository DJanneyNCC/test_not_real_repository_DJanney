/**
 * @file timer.h
 * @brief Provides for CPU timing
 * @author N. Lippincott, Northampton Community College
 */

#pragma once
#include <ctime>

/**
 * Provides for determining CPU time
 *
 * This class may be used to time sections of code to determine
 * CPU seconds used. Once a Timer object is created, any
 * subsequent calls to the seconds method will return the
 * number of CPU seconds used since the object was created.
 * The timing may be reset back to zero by calling the
 * reset method.
 */
class Timer {
private:
    clock_t clock_start;
public:
    /**
     * Initializes the timer
     */
    Timer() { reset(); }
    /**
     * Resets the timer to zero seconds
     */
    void reset() { clock_start = clock(); }
    /**
     * Returns number of seconds since construction or reset
     *
     * @return Number of CPU seconds
     */
    double seconds() { return (double(clock()) - double(clock_start)) / CLOCKS_PER_SEC; }
};