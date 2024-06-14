/*
Insertion (insert): Inserts elements into the set while maintaining the sorted order and ensuring uniqueness.

Deletion (erase): Removes elements from the set.

Search (find): Searches for an element in the set.

Iterators (begin, end): Provides iterators to traverse the set.

Size (size): Returns the number of elements in the set.

Emptiness (empty): Checks if the set is empty.

Clearing (clear): Removes all elements from the set.

Counting (count): Counts the occurrences of an element in the set (since elements are unique, it's either 0 or 1).

*/

#include <iostream>
#include <set>

int main() {
    // Create a set of integers
    std::set<int> mySet;

    // Inserting elements
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(2); // Ignored, as it's already present

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

    // Clearing the set
    mySet.clear();

    return 0;
}
