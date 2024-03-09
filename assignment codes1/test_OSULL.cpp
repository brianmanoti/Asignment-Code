#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "OSULL.h"

using namespace std;

// Function to generate random integer within a given range
int generateRandomInt(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

// Function to measure the performance for a given capacity
void measurePerformance(int capacity, const int listSize, const int numOperations) {
    OSULL<int, 10> osull; // Assuming node capacity of 10 for now

    clock_t start = clock();

    for (int i = 0; i < numOperations; ++i) {
        osull.insert(generateRandomInt(1, listSize * 10));
        osull.find(generateRandomInt(1, listSize * 10));
        osull.remove(generateRandomInt(1, listSize * 10));
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken for " << (numOperations * 3) << " operations OSULL with node capacity " << capacity << ": " << duration * 1000 << " milliseconds" << endl;
}

int main() {
    const int listSize = 10000; // Fixed list size
    const int numOperations = 1000; // Number of operations for each test
    constexpr int nodeCapacities[] = {5, 10, 20}; // Varying node capacities for OSULL

    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < sizeof(nodeCapacities) / sizeof(nodeCapacities[0]); ++i) {
        measurePerformance(nodeCapacities[i], listSize, numOperations);
    }

    return 0;
}

