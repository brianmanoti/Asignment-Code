#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random> // Include the <random> header for random_device, mt19937, and uniform_int_distribution

#include "OSULL.h"

using namespace std;

// Function to generate random integer within a given range
int generateRandomInt(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

// Function to measure the performance of operations on OSULL
template<int initNodeCapacity>
void measurePerformance_OSULL(OSULL<int, initNodeCapacity>& osull, int listSize, int numOperations) {
    clock_t start = clock();

    // Perform a series of operations (insertions, searches, removals)
    for (int i = 0; i < numOperations; ++i) {
        // Perform an insertion operation
        osull.insert(generateRandomInt(1, listSize * 10));

        // Perform a search operation
        osull.find(generateRandomInt(1, listSize * 10));

        // Perform a removal operation
        osull.remove(generateRandomInt(1, listSize * 10));
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken for " << (numOperations * 3) << " operations on OSULL with list size " << listSize << " and node capacity " << initNodeCapacity << ": " << duration * 1000 << " milliseconds" << endl;
}

int main() {
    const int listSizes[] = {1000, 10000, 100000}; // Varying list sizes
    const int numOperations = 1000; // Number of operations for each test

    srand(time(0)); // Seed the random number generator

    for (int size : listSizes) {
        for (int i = 0; i < 3; ++i) { // Loop index instead of loop variable
            // Create an instance of OSULL with current node capacity
            int capacity = i == 0 ? 5 : (i == 1 ? 10 : 20); // Assign capacity based on loop index
            OSULL<int, capacity> osull;

            // Populate OSULL with random integers
            for (int i = 1; i <= size; ++i) {
                osull.insert(i);
            }

            // Measure performance for OSULL with current list size and node capacity
            measurePerformance_OSULL(osull, size, numOperations);
        }
    }

    return 0;
}
