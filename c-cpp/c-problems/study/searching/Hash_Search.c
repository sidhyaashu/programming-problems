#include <stdio.h>

#define TABLE_SIZE 10

// Structure to represent a hash table entry
typedef struct {
    int key;
    int value;
} HashEntry;

// Hash table structure
typedef struct {
    HashEntry table[TABLE_SIZE];
} HashMap;

// Initialize hash table
void initialize(HashMap* hashMap) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashMap->table[i].key = -1; // Initialize all keys to -1 (indicating empty)
    }
}

// Hash function to generate index from key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert key-value pair into hash table
void insert(HashMap* hashMap, int key, int value) {
    int index = hash(key);
    while (hashMap->table[index].key != -1) { // Linear probing for collision resolution
        index = (index + 1) % TABLE_SIZE;
    }
    hashMap->table[index].key = key;
    hashMap->table[index].value = value;
}

// Search for key in hash table
int search(HashMap* hashMap, int key) {
    int index = hash(key);
    int initialIndex = index;
    while (hashMap->table[index].key != key && hashMap->table[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == initialIndex) { // Reached starting index, element not found
            return -1;
        }
    }
    if (hashMap->table[index].key == key) {
        return index; // Return index if key is found
    }
    return -1; // Key not found
}

int main() {
    HashMap hashMap;
    initialize(&hashMap);

    insert(&hashMap, 5, 50);
    insert(&hashMap, 15, 150);
    insert(&hashMap, 25, 250);
    insert(&hashMap, 35, 350);

    int keyToSearch = 15;
    int index = search(&hashMap, keyToSearch);
    if (index != -1) {
        printf("Key %d found at index %d with value %d.\n", keyToSearch, index, hashMap.table[index].value);
    } else {
        printf("Key %d not found.\n", keyToSearch);
    }

    return 0;
}
