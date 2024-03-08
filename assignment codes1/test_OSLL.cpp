#include <iostream>
#include <chrono>
#include "OSLL.h" // Include the header file for OSLL

using namespace std;
using namespace std::chrono;

// Function to generate random integer within a given range
int generateRandomInt(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

// Function to measure the performance of operations on OSLL
void measurePerformance_OSLL(OSLL<int>& osll, int listSize, int numOperations) {
    auto start = high_resolution_clock::now();

    // Perform a series of operations (insertions, searches, removals)
    for (int i = 0; i < numOperations; ++i) {
        // Perform an insertion operation
        osll.insert(generateRandomInt(1, listSize * 10));

        // Perform a search operation
        osll.find(generateRandomInt(1, listSize * 10));

        // Perform a removal operation
        osll.remove(generateRandomInt(1, listSize * 10));
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Time taken for " << (numOperations * 3) << " operations on OSLL with list size " << listSize << ": " << duration.count() << " milliseconds" << endl;
}

int main() {
    const int listSizes[] = {1000, 10000, 100000}; // Varying list sizes
    const int numOperations = 1000; // Number of operations for each test

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
