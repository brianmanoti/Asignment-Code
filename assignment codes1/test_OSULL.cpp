#include <iostream>
#include "OSULL.h"

int main() {
    // Create an instance of OSULL with initial node capacity of 5
    OSULL<int, 5> osull;

    // Insert some elements into the ordered set
    osull.insert(5);
    osull.insert(10);
    osull.insert(3);
    osull.insert(8);

    // Display the contents of the ordered set
    std::cout << "Ordered Set contents: ";
    osull.display();
    std::cout << std::endl;

    // Check if certain elements exist in the ordered set
    std::cout << "Is 5 in the ordered set? " << (osull.find(5) ? "Yes" : "No") << std::endl;
    std::cout << "Is 7 in the ordered set? " << (osull.find(7) ? "Yes" : "No") << std::endl;

    // Remove an element from the ordered set
    osull.remove(5);

    // Display the updated contents of the ordered set
    std::cout << "Ordered Set contents after removing 5: ";
    osull.display();
    std::cout << std::endl;

    return 0;
}
