/*
insert(key, value): Inserts a key-value pair into the map. If the key already exists, updates its value.
operator[]: Inserts or accesses the value associated with the given key. If the key doesn't exist, inserts a default-constructed value.
size(): Returns the number of elements in the map.
iterate(): Iterates over the map and prints each key-value pair.
contains(key): Checks if the map contains the given key.
erase(key): Removes the element with the specified key from the map.
clear(): Removes all elements from the map.
empty(): Checks if the map is empty.
*/

#include <iostream>
#include <vector>
#include <algorithm>

template<typename Key, typename Value>
class CustomMap {
private:
    std::vector<std::pair<Key, Value>> data;

public:
    // Insertion
    void insert(const Key& key, const Value& value) {
        auto it = std::find_if(data.begin(), data.end(),
            [&](const std::pair<Key, Value>& pair) { return pair.first == key; });

        if (it != data.end()) {
            // If key already exists, update its value
            it->second = value;
        } else {
            // Otherwise, insert a new key-value pair
            data.push_back(std::make_pair(key, value));
        }
    }

    // Accessing elements
    Value& operator[](const Key& key) {
        auto it = std::find_if(data.begin(), data.end(),
            [&](const std::pair<Key, Value>& pair) { return pair.first == key; });

        if (it != data.end()) {
            return it->second;
        } else {
            // If key doesn't exist, insert a default-constructed value
            insert(key, Value());
            return data.back().second;
        }
    }

    // Size
    size_t size() const {
        return data.size();
    }

    // Iterating over the map
    void iterate() const {
        for (const auto& pair : data) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }

    // Check if a key exists
    bool contains(const Key& key) const {
        return std::find_if(data.begin(), data.end(),
            [&](const std::pair<Key, Value>& pair) { return pair.first == key; }) != data.end();
    }

    // Deletion
    void erase(const Key& key) {
        data.erase(std::remove_if(data.begin(), data.end(),
            [&](const std::pair<Key, Value>& pair) { return pair.first == key; }), data.end());
    }

    // Clear the map
    void clear() {
        data.clear();
    }

    // Check if the map is empty
    bool empty() const {
        return data.empty();
    }
};

int main() {
    CustomMap<int, std::string> myMap;

    // Insertion
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap[3] = "Three"; // Insertion using subscript operator

    // Accessing elements
    std::cout << "Value for key 2: " << myMap[2] << std::endl;

    // Size
    std::cout << "Size of the map: " << myMap.size() << std::endl;

    // Iterating over the map
    myMap.iterate();

    // Check if a key exists
    if (myMap.contains(3)) {
        std::cout << "Key 3 exists in the map." << std::endl;
    }

    // Deletion
    myMap.erase(1); // Erase by key

    // Clear the map
    myMap.clear();

    // Check if the map is empty
    if (myMap.empty()) {
        std::cout << "Map is empty." << std::endl;
    }

    return 0;
}
