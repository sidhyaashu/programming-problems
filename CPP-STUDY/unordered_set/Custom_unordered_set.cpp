#include <iostream>
#include <vector>
#include <functional> // For std::hash

// Custom implementation of unordered set
template<typename T>
class CustomUnorderedSet {
private:
    std::vector<std::vector<T>> buckets; // Vector of vectors for buckets
    std::hash<T> hashFunction; // Hash function

    // Helper function to get bucket index for a given key
    size_t getBucketIndex(const T& key) const {
        return hashFunction(key) % buckets.size();
    }

public:
    // Constructor
    CustomUnorderedSet(size_t bucketCount = 10) : buckets(bucketCount) {}

    // Insertion operation
    void insert(const T& key) {
        size_t index = getBucketIndex(key);
        for (const auto& elem : buckets[index]) {
            if (elem == key) {
                return; // Key already exists
            }
        }
        buckets[index].push_back(key); // Add the key to the bucket
    }

    // Deletion operation
    void erase(const T& key) {
        size_t index = getBucketIndex(key);
        auto& bucket = buckets[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it); // Remove the key from the bucket
        }
    }

    // Find operation
    bool find(const T& key) {
        size_t index = getBucketIndex(key);
        for (const auto& elem : buckets[index]) {
            if (elem == key) {
                return true; // Key found
            }
        }
        return false; // Key not found
    }

    // Size operation
    size_t size() const {
        size_t count = 0;
        for (const auto& bucket : buckets) {
            count += bucket.size();
        }
        return count;
    }

    // Empty operation
    bool empty() const {
        return size() == 0;
    }

    // Iterators
    // For demonstration purposes, iterators are not implemented here
};

int main() {
    // Create a custom unordered set
    CustomUnorderedSet<int> mySet;

    // Insertion
    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(15);

    // Deletion
    mySet.erase(10);

    // Find
    if (mySet.find(10)) {
        std::cout << "Element 10 exists in the set." << std::endl;
    } else {
        std::cout << "Element 10 does not exist in the set." << std::endl;
    }

    // Size
    std::cout << "Size of set: " << mySet.size() << std::endl;

    // Empty
    if (mySet.empty()) {
        std::cout << "Set is empty." << std::endl;
    } else {
        std::cout << "Set is not empty." << std::endl;
    }

    return 0;
}
