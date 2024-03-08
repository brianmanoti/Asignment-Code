#include <iostream>
#include "OSULL.h"

using namespace std;

int main() {
    // Create an instance of OSULL with a node capacity of 5
    OSULL<int, 5> osull;

    // Test insertions
    cout << "Testing insertions:" << endl;
    for (int i = 1; i <= 20; ++i) {
        osull.insert(i);
    }
    cout << "OSULL after insertions: ";
    osull.display();
    cout << endl;

    // Test searches
    cout << "Testing searches:" << endl;
    cout << "Searching for 5: " << (osull.find(5) ? "Found" : "Not found") << endl;
    cout << "Searching for 25: " << (osull.find(25) ? "Found" : "Not found") << endl;

    // Test removals
    cout << "Testing removals:" << endl;
    for (int i = 1; i <= 10; ++i) {
        osull.remove(i);
    }
    cout << "OSULL after removals: ";
    osull.display();
    cout << endl;

    return 0;
}
