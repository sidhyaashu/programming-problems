#include <iostream>
#include <unordered_set>

int main() {
    // 1. Constructor: Constructs an empty unordered set
    std::unordered_set<int> mySet;

    // 2. Insertion: Inserts elements into the set
    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(15);

    // 3. Deletion: Removes an element from the set
    mySet.erase(10);

    // 4. Find: Searches for an element in the set
    auto it = mySet.find(10);
    if (it != mySet.end()) {
        std::cout << "Element 10 exists in the set." << std::endl;
    } else {
        std::cout << "Element 10 does not exist in the set." << std::endl;
    }

    // 5. Size: Returns the number of elements in the set
    std::cout << "Size of set: " << mySet.size() << std::endl;

    // 6. Empty: Checks if the set is empty
    if (mySet.empty()) {
        std::cout << "Set is empty." << std::endl;
    } else {
        std::cout << "Set is not empty." << std::endl;
    }

    // 7. Iterators: Iterates over the elements in the set
    std::cout << "Elements in the set: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 8. Bucket Interface: Provides information about the underlying bucket structure
    std::cout << "Bucket count: " << mySet.bucket_count() << std::endl;

    // 9. Load Factor: Provides information about load factor and allows control over it
    std::cout << "Load factor: " << mySet.load_factor() << std::endl;

    // 10. Swap: Swaps the contents of two unordered sets
    std::unordered_set<int> otherSet = {100, 200};
    mySet.swap(otherSet);

    // 11. Clear: Removes all elements from the set
    mySet.clear();

    // 12. Equality: Checks equality between two sets
    std::unordered_set<int> set1 = {1, 2, 3};
    std::unordered_set<int> set2 = {1, 2, 3};
    if (set1 == set2) {
        std::cout << "Sets set1 and set2 are equal." << std::endl;
    }

    // 13. Fast Lookup: Provides fast lookup using hashing
    // 14. Unique Elements: Ensures all elements in the set are unique
    // 15. Dynamic Sizing: Automatically adjusts the size of the underlying hash table
    // 16. Custom Hashing: Supports custom hash functions and equality comparison functions

    return 0;
}
