#include <iostream>
#include <cstdlib>
#include <ctime>
#include "OSULL.h"

using namespace std;

int main() {
    const int listSize = 10000; // Fixed list size
    const int numOperations = 1000; // Number of operations for each test
    const int nodeCapacities[] = {5, 10, 20}; // Varying node capacities for OSULL

    srand(time(0)); // Seed the random number generator

    for (int capacity : nodeCapacities) {
        // Create an instance of OSULL with current node capacity
        OSULL<int, capacity> osull;

        // Populate OSULL with random integers
        for (int i = 1; i <= listSize; ++i) {
            osull.insert(i);
        }

        // Measure performance for OSULL with current node capacity
        clock_t start = clock();

        // Perform a series of operations (insertions, searches, removals)
        for (int i = 0; i < numOperations; ++i) {
            // Perform an insertion operation
            osull.insert(rand() % (listSize * 10) + 1);

            // Perform a search operation
            osull.find(rand() % (listSize * 10) + 1);

            // Perform a removal operation
            osull.remove(rand() % (listSize * 10) + 1);
        }

        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;

        cout << "Time taken for " << (numOperations * 3) << " operations on OSULL with node capacity " << capacity << ": " << duration * 1000 << " milliseconds" << endl;
    }

    return 0;
}