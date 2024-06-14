/*
I've added a rehashing mechanism to the insert function, which increases the size of the buckets when the load factor exceeds a certain threshold (0.75 in this case).
I've introduced a numElements member variable to keep track of the number of elements in the map, which is used in calculating the load factor and rehashing.
The erase function now decrements the numElements count when removing an element.
The size function now returns the value of numElements.
I've set an initial bucket size and a maximum load factor as constants to govern the behavior of the map.

*/

#include <iostream>
#include <vector>
#include <utility>
#include <functional>

template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class MyUnorderedMap {
private:
    using KeyValuePair = std::pair<KeyType, ValueType>;
    std::vector<KeyValuePair> buckets[10];
    Hash hashFunction;
    size_t numElements = 0;
    static constexpr size_t INITIAL_BUCKET_SIZE = 10;
    static constexpr double MAX_LOAD_FACTOR = 0.75;

    size_t getHashIndex(const KeyType& key) const {
        return hashFunction(key) % INITIAL_BUCKET_SIZE;
    }

    void rehash() {
        if (static_cast<double>(numElements) / INITIAL_BUCKET_SIZE > MAX_LOAD_FACTOR) {
            std::vector<KeyValuePair> newBuckets[INITIAL_BUCKET_SIZE * 2];
            for (auto& bucket : buckets) {
                for (auto& pair : bucket) {
                    size_t index = hashFunction(pair.first) % (INITIAL_BUCKET_SIZE * 2);
                    newBuckets[index].push_back(pair);
                }
            }
            std::swap(buckets, newBuckets);
            INITIAL_BUCKET_SIZE *= 2;
        }
    }

public:
    void insert(const KeyType& key, const ValueType& value) {
        rehash();
        size_t index = getHashIndex(key);
        buckets[index].push_back(std::make_pair(key, value));
        ++numElements;
    }

    ValueType& operator[](const KeyType& key) {
        size_t index = getHashIndex(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    void erase(const KeyType& key) {
        size_t index = getHashIndex(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --numElements;
                return;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool contains(const KeyType& key) const {
        size_t index = getHashIndex(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return numElements;
    }

    bool empty() const {
        return size() == 0;
    }

    void forEach(const std::function<void(const KeyType&, const ValueType&)>& func) const {
        for (const auto& bucket : buckets) {
            for (const auto& pair : bucket) {
                func(pair.first, pair.second);
            }
        }
    }
};

int main() {
    MyUnorderedMap<int, std::string> myMap;

    // Inserting elements
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");
    myMap.insert(4, "Four");
    myMap.insert(5, "Five");
    myMap.insert(6, "Six");

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
