#include <iostream>
#include <ctime>
#include "OSULL.h" // Assuming the OSULL class is defined in OSULL.h

using namespace std;

// Test function to measure performance of OSULL and OSLL
void testPerformance(int listSize, int numOperations) {
    // Create instances of OSULL and OSLL
    OSULL<int> osull;
    OSLL<int> osll;

    // Measure insertion time for OSULL
    clock_t start = clock();
    for (int i = 0; i < numOperations; ++i) {
        osull.insert(i);
    }
    clock_t end = clock();
    double durationOSULLInsert = double(end - start) / CLOCKS_PER_SEC;

    // Measure insertion time for OSLL
    start = clock();
    for (int i = 0; i < numOperations; ++i) {
        osll.insert(i);
    }
    end = clock();
    double durationOSLLInsert = double(end - start) / CLOCKS_PER_SEC;

    // Measure search time for OSULL
    start = clock();
    for (int i = 0; i < numOperations; ++i) {
        osull.find(i);
    }
    end = clock();
    double durationOSULLSearch = double(end - start) / CLOCKS_PER_SEC;

    // Measure search time for OSLL
    start = clock();
    for (int i = 0; i < numOperations; ++i) {
        osll.find(i);
    }
    end = clock();
    double durationOSLLSearch = double(end - start) / CLOCKS_PER_SEC;

    // Measure removal time for OSULL
    start = clock();
    for (int i = 0; i < numOperations; ++i) {
        osull.remove(i);
    }
    end = clock();
    double durationOSULLRemove = double(end - start) / CLOCKS_PER_SEC;

    // Measure removal time for OSLL
    start = clock();
    for (int i = 0; i < numOperations; ++i) {
        osll.remove(i);
    }
    end = clock();
    double durationOSLLRemove = double(end - start) / CLOCKS_PER_SEC;

    // Display results
    cout << "Performance Comparison:" << endl;
    cout << "List Size: " << listSize << endl;
    cout << "Number of Operations: " << numOperations << endl;
    cout << "OSULL Insertion Time: " << durationOSULLInsert << " seconds" << endl;
    cout << "OSLL Insertion Time: " << durationOSLLInsert << " seconds" << endl;
    cout << "OSULL Search Time: " << durationOSULLSearch << " seconds" << endl;
    cout << "OSLL Search Time: " << durationOSLLSearch << " seconds" << endl;
    cout << "OSULL Removal Time: " << durationOSULLRemove << " seconds" << endl;
    cout << "OSLL Removal Time: " << durationOSLLRemove << " seconds" << endl;
}

int main() {
    int listSize = 10000; // Adjust list size as needed
    int numOperations = 1000; // Adjust number of operations as needed

    testPerformance(listSize, numOperations);

    return 0;
}
