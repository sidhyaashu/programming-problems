/*
We define a MyUnorderedMap class template that represents our custom unordered map.
We use a vector to store key-value pairs, where each index in the vector is determined by the hash value of the key.
We implement basic operations such as insert, operator[], erase, contains, size, empty, and forEach (for iterating over the map).
In the main function, we demonstrate the usage of our custom unordered map by inserting elements, accessing elements, checking for key existence, getting the size, removing elements, checking if empty, and iterating over the map.
*/


#include <iostream>
#include <vector>
#include <utility>

// Custom implementation of unordered map
template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class MyUnorderedMap {
private:
    // Pair for key-value storage
    using KeyValuePair = std::pair<KeyType, ValueType>;
    // Vector of key-value pairs
    std::vector<KeyValuePair> buckets[10]; // Fixed size for simplicity
    Hash hashFunction;

    // Hash function to get index in the vector
    size_t getHashIndex(const KeyType& key) const {
        return hashFunction(key) % 10;
    }

public:
    // Insert key-value pair into the map
    void insert(const KeyType& key, const ValueType& value) {
        size_t index = getHashIndex(key);
        buckets[index].push_back(std::make_pair(key, value));
    }

    // Search for a key and return its value
    ValueType& operator[](const KeyType& key) {
        size_t index = getHashIndex(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Remove key-value pair from the map
    void erase(const KeyType& key) {
        size_t index = getHashIndex(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Check if key exists in the map
    bool contains(const KeyType& key) const {
        size_t index = getHashIndex(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    // Get the size of the map
    size_t size() const {
        size_t size = 0;
        for (const auto& bucket : buckets) {
            size += bucket.size();
        }
        return size;
    }

    // Check if the map is empty
    bool empty() const {
        return size() == 0;
    }

    // Iterating over the map
    void forEach(const std::function<void(const KeyType&, const ValueType&)>& func) const {
        for (const auto& bucket : buckets) {
            for (const auto& pair : bucket) {
                func(pair.first, pair.second);
            }
        }
    }
};

int main() {
    // Creating custom unordered map
    MyUnorderedMap<int, std::string> myMap;

    // Inserting elements
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");

    // Accessing elements
    std::cout << "Value at key 1: " << myMap[1] << std::endl;

    // Checking if a key exists
    if (myMap.contains(2)) {
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
    myMap.forEach([](const int& key, const std::string& value) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    });

    return 0;
}
