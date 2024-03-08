#include <iostream>
#include "OSULL.h" // Include the header file for OSULL

int main() {
    // Test OSULL functionality
    OSULL<int, 5> osull; // Using node capacity of 5

    std::cout << "Inserting elements into OSULL..." << std::endl;
    osull.insert(5);
    osull.insert(10);
    osull.insert(3);
    osull.insert(8);

    std::cout << "Displaying OSULL contents: ";
    osull.display();
    std::cout << std::endl;

    std::cout << "Minimum element in OSULL: " << osull.getMin() << std::endl;
    std::cout << "Maximum element in OSULL: " << osull.getMax() << std::endl;

    std::cout << "Finding elements in OSULL..." << std::endl;
    std::cout << "Find 5: " << (osull.find(5) ? "Found" : "Not found") << std::endl;
    std::cout << "Find 15: " << (osull.find(15) ? "Found" : "Not found") << std::endl;

    std::cout << "Removing elements from OSULL..." << std::endl;
    std::cout << "Remove 3: " << (osull.remove(3) ? "Removed" : "Not found") << std::endl;
    std::cout << "Remove 15: " << (osull.remove(15) ? "Removed" : "Not found") << std::endl;

    std::cout << "Displaying OSULL contents after removal: ";
    osull.display();
    std::cout << std::endl;

    return 0;
}
