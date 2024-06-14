/*
insert(key, value): Inserts a key-value pair into the map.
[] operator: Inserts or accesses the value associated with the given key.
size(): Returns the number of elements in the map.
begin(), end(): Returns iterators pointing to the beginning and end of the map, respectively.
find(key): Searches the map for the element with the specified key and returns an iterator to it if found, or end() otherwise.
erase(key): Removes the element with the specified key from the map.
clear(): Removes all elements from the map.
empty(): Checks if the map is empty.
*/

#include <iostream>
#include <map>

int main() {
    // Declaration
    std::map<int, std::string> myMap;

    // Insertion
    myMap.insert(std::make_pair(1, "One"));
    myMap.insert(std::make_pair(2, "Two"));
    myMap[3] = "Three"; // Insertion using subscript operator

    // Accessing elements
    std::cout << "Value for key 2: " << myMap[2] << std::endl;

    // Size
    std::cout << "Size of the map: " << myMap.size() << std::endl;

    // Iterating over the map
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    // Check if a key exists
    if (myMap.find(3) != myMap.end()) {
        std::cout << "Key 3 exists in the map." << std::endl;
    }

    // Deletion
    myMap.erase(1); // Erase by key
    // Alternatively, erase by iterator
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        myMap.erase(it);
    }

    // Clear the map
    myMap.clear();

    // Check if the map is empty
    if (myMap.empty()) {
        std::cout << "Map is empty." << std::endl;
    }

    return 0;
}
