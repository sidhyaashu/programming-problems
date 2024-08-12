/*
more advanced operations such as range-based insertion, lower_bound, upper_bound, and equal_range. These operations are useful for more sophisticated manipulations of sets.

*/


#include <iostream>
#include <set>

int main() {
    // Create a set of integers
    std::set<int> mySet;

    // Inserting elements using range-based insertion
    mySet.insert({5, 2, 8, 2, 9, 3, 7});

    // Size of the set
    std::cout << "Size of set: " << mySet.size() << std::endl;

    // Checking if set is empty
    if (mySet.empty()) {
        std::cout << "Set is empty" << std::endl;
    } else {
        std::cout << "Set is not empty" << std::endl;
    }

    // Searching for an element
    auto it = mySet.find(5);
    if (it != mySet.end()) {
        std::cout << "Element 5 found in the set" << std::endl;
    } else {
        std::cout << "Element 5 not found in the set" << std::endl;
    }

    // Deleting an element
    mySet.erase(2);

    // Displaying elements using iterators
    std::cout << "Elements of set:";
    for (auto elem : mySet) {
        std::cout << " " << elem;
    }
    std::cout << std::endl;

    // Using lower_bound and upper_bound
    auto lower = mySet.lower_bound(3); // First element not less than 3
    auto upper = mySet.upper_bound(7); // First element greater than 7

    std::cout << "Elements between 3 and 7:";
    for (auto it = lower; it != upper; ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Using equal_range
    auto range = mySet.equal_range(5); // Elements with key = 5
    std::cout << "Elements with key 5:";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Clearing the set
    mySet.clear();

    return 0;
}
