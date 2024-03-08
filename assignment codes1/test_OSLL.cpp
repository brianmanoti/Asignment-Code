#include <iostream>
#include "OSLL.h"

using namespace std;

int main() {
    // Create an instance of OSLL
    OSLL<int> osll;

    // Test insertions
    cout << "Testing insertions:" << endl;
    osll.insert(5);
    osll.insert(10);
    osll.insert(3);
    osll.insert(8);
    osll.insert(7);
    cout << "OSLL after insertions: ";
    osll.display();
    cout << endl;

    // Test searches
    cout << "Testing searches:" << endl;
    cout << "Searching for 3: " << (osll.find(3) ? "Found" : "Not found") << endl;
    cout << "Searching for 6: " << (osll.find(6) ? "Found" : "Not found") << endl;

    // Test removals
    cout << "Testing removals:" << endl;
    osll.remove(5);
    osll.remove(7);
    cout << "OSLL after removals: ";
    osll.display();
    cout << endl;

    return 0;
}

