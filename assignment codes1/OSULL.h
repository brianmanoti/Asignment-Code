#include <iostream>
#include <chrono> // Include for measuring time
#include "OSULL.h"

using namespace std;
using namespace std::chrono; // Namespace for chrono library

int main() {
    // Create an instance of OSULL with default node capacity
    OSULL<int> osull;

    // Insert some elements into the OSULL
    osull.insert(10);
    osull.insert(20);
    osull.insert(30);
    osull.insert(15);

    // Measure the time taken for the operations
    auto start = high_resolution_clock::now();

    // Display the size of the OSULL
    cout << "Size of OSULL: " << osull.get_size() << endl;

    // Display the contents of the OSULL
    cout << "Contents of OSULL: ";
    osull.display();
    cout << endl;

    // Search for an element in the OSULL
    int searchValue = 20;
    if (osull.find(searchValue)) {
        cout << "Element " << searchValue << " found in OSULL" << endl;
    } else {
        cout << "Element " << searchValue << " not found in OSULL" << endl;
    }

    // Remove an element from the OSULL
    int removeValue = 15;
    if (osull.remove(removeValue)) {
        cout << "Element " << removeValue << " removed from OSULL" << endl;
    } else {
        cout << "Element " << removeValue << " not found in OSULL" << endl;
    }

    // Display the updated size and contents of the OSULL
    cout << "Updated size of OSULL: " << osull.get_size() << endl;
    cout << "Updated contents of OSULL: ";
    osull.display();
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
