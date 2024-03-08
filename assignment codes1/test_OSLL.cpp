#include <iostream>
#include "OSLL.h" // Include the header file for OSLL

int main() {
    // Test OSLL functionality
    OSLL<int> osll;

    std::cout << "Inserting elements into OSLL..." << std::endl;
    osll.insert(5);
    osll.insert(10);
    osll.insert(3);
    osll.insert(8);

    std::cout << "Displaying OSLL contents: ";
    osll.display();
    std::cout << std::endl;

    std::cout << "Minimum element in OSLL: " << osll.getMin() << std::endl;
    std::cout << "Maximum element in OSLL: " << osll.getMax() << std::endl;

    std::cout << "Finding elements in OSLL..." << std::endl;
    std::cout << "Find 5: " << (osll.find(5) ? "Found" : "Not found") << std::endl;
    std::cout << "Find 15: " << (osll.find(15) ? "Found" : "Not found") << std::endl;

    std::cout << "Removing elements from OSLL..." << std::endl;
    std::cout << "Remove 3: " << (osll.remove(3) ? "Removed" : "Not found") << std::endl;
    std::cout << "Remove 15: " << (osll.remove(15) ? "Removed" : "Not found") << std::endl;

    std::cout << "Displaying OSLL contents after removal: ";
    osll.display();
    std::cout << std::endl;

    return 0;
}
