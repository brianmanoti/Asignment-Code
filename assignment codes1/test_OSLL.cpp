#include <iostream>
#include <cstdlib> // Include the header file for rand()
#include <ctime>   // Include the header file for time()

#include "OSLL.h" // Include the header file for OSLL

using namespace std;

// Function to generate random integer within a given range
int generateRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to measure the performance of operations on OSLL
void measurePerformance_OSLL(OSLL<int>& osll, int listSize, int numOperations) {
    clock_t start = clock();

    // Perform a series of operations (insertions, searches, removals)
    for (int i = 0; i < numOperations; ++i) {
        // Perform an insertion operation
        osll.insert(generateRandomInt(1, listSize * 10));

        // Perform a search operation
        osll.find(generateRandomInt(1, listSize * 10));

        // Perform a removal operation
        osll.remove(generateRandomInt(1, listSize * 10));
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken for " << (numOperations * 3) << " operations on OSLL with list size " << listSize << ": " << duration * 1000 << " milliseconds" << endl;
}

int main() {
    const int listSizes[] = {1000, 10000, 100000}; // Varying list sizes
    const int numOperations = 1000; // Number of operations for each test

    // Seed the random number generator
    srand(time(0));

    for (int size : listSizes) {
        // Create an instance of OSLL
        OSLL<int> osll;

        // Populate OSLL with random integers
        for (int i = 1; i <= size; ++i) {
            osll.insert(i);
        }

        // Measure performance for OSLL with current list size
        measurePerformance_OSLL(osll, size, numOperations);
    }

    return 0;
}
