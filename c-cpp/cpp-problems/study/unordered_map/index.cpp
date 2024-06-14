/*
Creation of an unordered_map named myMap.
Insertion of elements using insert and emplace methods.
Accessing elements using the subscript operator [].
Checking if a key exists using find.
Getting the size of the map using size.
Removing elements using erase.
Checking if the map is empty using empty.
Iterating over the map using a range-based for loop.
*/

#include <iostream>
#include <unordered_map>

int main() {
    // Creating an unordered_map
    std::unordered_map<int, std::string> myMap;

    // Inserting elements
    myMap.insert({1, "One"});
    myMap.emplace(2, "Two");

    // Accessing elements
    std::cout << "Value at key 1: " << myMap[1] << std::endl;

    // Check if a key exists
    if (myMap.find(2) != myMap.end()) {
        std::cout << "Key 2 exists." << std::endl;
    }

    // Size of the map
    std::cout << "Size of map: " << myMap.size() << std::endl;

    // Removing elements
    myMap.erase(1);

    // Check if empty
    if (myMap.empty()) {
        std::cout << "Map is empty." << std::endl;
    } else {
        std::cout << "Map is not empty." << std::endl;
    }

    // Iterating over the map
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
