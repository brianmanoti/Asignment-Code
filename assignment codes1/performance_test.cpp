#include <iostream>
#include <chrono>
#include <random>
#include "OSLL.h"  // Assuming you have implemented OSLL.h and OSLL.cpp
#include "OSULL.h" // Assuming you have implemented OSULL.h and OSULL.cpp

using namespace std;
using namespace std::chrono;

// Function to generate random integer within a given range
int generateRandomInt(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

// Function to populate the ordered set with random integers
template<typename OrderedSet>
void populateSet(OrderedSet& set, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        set.insert(generateRandomInt(minVal, maxVal));
    }
}

// Function to measure the time taken for a series of operations on the ordered set
template<typename OrderedSet>
void measurePerformance(OrderedSet& set, int numOperations) {
    auto start = high_resolution_clock::now();

    // Perform a series of operations (e.g., insertions, searches, removals)
    for (int i = 0; i < numOperations; ++i) {
        // Perform an insertion operation
        set.insert(generateRandomInt(1, 1000));

        // Perform a search operation
        set.find(generateRandomInt(1, 1000));

        // Perform a removal operation
        set.remove(generateRandomInt(1, 1000));
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Time taken for " << (numOperations * 3) << " operations: " << duration.count() << " milliseconds" << endl;
}

int main() {
    const int listSize = 10000; // Adjust the list size as needed
    const int minVal = 1;
    const int maxVal = 100000; // Adjust the range of values as needed
    const int numOperations = 1000; // Adjust the number of operations as needed

    // Create instances of OSLL and OSULL
    OSLL<int> osll;
    OSULL<int> osull;

    // Populate both sets with random integers
    populateSet(osll, listSize, minVal, maxVal);
    populateSet(osull, listSize, minVal, maxVal);

    // Measure performance for a series of operations on OSLL
    cout << "Performance for OSLL:" << endl;
    measurePerformance(osll, numOperations);

    // Measure performance for a series of operations on OSULL
    cout << "Performance for OSULL:" << endl;
    measurePerformance(osull, numOperations);

    return 0;
}

