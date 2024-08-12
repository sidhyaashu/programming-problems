/*
Iterator support: We define an iterator class nested inside CustomMap to enable iteration over the map using a range-based for loop.
begin() and end() methods: These methods return iterators pointing to the beginning and end of the map, respectively.
find(key) method: This method returns an iterator pointing to the element with the specified key, similar to the find method in the standard library.
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
    class iterator {
    private:
        typename std::vector<std::pair<Key, Value>>::iterator it;
    public:
        iterator(typename std::vector<std::pair<Key, Value>>::iterator itr) : it(itr) {}

        iterator& operator++() {
            ++it;
            return *this;
        }

        std::pair<Key, Value>& operator*() {
            return *it;
        }

        bool operator!=(const iterator& other) const {
            return it != other.it;
        }
    };

    iterator begin() {
        return iterator(data.begin());
    }

    iterator end() {
        return iterator(data.end());
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

    // Find value for a key
    typename std::vector<std::pair<Key, Value>>::iterator find(const Key& key) {
        return std::find_if(data.begin(), data.end(),
            [&](const std::pair<Key, Value>& pair) { return pair.first == key; });
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

    // Iterating over the map using range-based for loop
    for (auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Check if a key exists
    if (myMap.contains(3)) {
        std::cout << "Key 3 exists in the map." << std::endl;
    }

    // Deletion
    myMap.erase(1); // Erase by key

    // Find method
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Value for key 2: " << it->second << std::endl;
    }

    // Clear the map
    myMap.clear();

    // Check if the map is empty
    if (myMap.empty()) {
        std::cout << "Map is empty." << std::endl;
    }

    return 0;
}
