/*

A hash table, also known as a hash map, is a data structure that implements an associative array abstract data type, a structure that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. Hash tables offer efficient lookup, insertion, and deletion operations.
*/


/*
Hash Function: A hash function maps keys to indices in the array. It should distribute keys uniformly across the array to minimize collisions.
Collision Resolution: Collisions occur when two different keys hash to the same index. Various techniques are used to handle collisions, such as chaining or open addressing.
Chaining: In chaining, each slot in the hash table contains a linked list of key-value pairs that hash to the same index.
Load Factor: The load factor is the ratio of the number of elements stored in the hash table to the size of the hash table.
Resize: When the load factor exceeds a certain threshold, the hash table is resized to maintain efficiency.
Open Addressing: In open addressing, collisions are resolved by probing for an empty slot in the table.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Structure for a hash table entry
struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
};

// Structure for a hash table
struct HashTable {
    struct HashNode* table[TABLE_SIZE];
};

// Hash function example (simple string hash)
int hash(char* key) {
    int hash = 0;
    while (*key)
        hash += *key++;
    return hash % TABLE_SIZE;
}

// Function to create a new hash node
struct HashNode* createNode(char* key, int value) {
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = strdup(key); // Copy key string
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a hash table
struct HashTable* createTable() {
    struct HashTable* newTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; ++i)
        newTable->table[i] = NULL;
    return newTable;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* ht, char* key, int value) {
    int index = hash(key);
    struct HashNode* newNode = createNode(key, value);

    // Collision resolution (Chaining)
    if (ht->table[index] == NULL)
        ht->table[index] = newNode;
    else {
        struct HashNode* current = ht->table[index];
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
}

// Function to search for a key in the hash table
int search(struct HashTable* ht, char* key) {
    int index = hash(key);
    struct HashNode* current = ht->table[index];

    while (current) {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return -1; // Key not found
}

// Function to delete a key-value pair from the hash table
void delete(struct HashTable* ht, char* key) {
    int index = hash(key);
    struct HashNode* current = ht->table[index];
    struct HashNode* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev)
                prev->next = current->next;
            else
                ht->table[index] = current->next;
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to display the contents of the hash table
void display(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct HashNode* current = ht->table[i];
        printf("[%d]: ", i);
        while (current) {
            printf("(%s,%d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    struct HashTable* ht = createTable();

    // Inserting key-value pairs
    insert(ht, "John", 21);
    insert(ht, "Alice", 32);
    insert(ht, "Bob", 44);

    // Displaying hash table
    printf("Hash Table:\n");
    display(ht);

    // Searching for a key
    printf("\nValue of Alice: %d\n", search(ht, "Alice"));

    // Deleting a key
    delete(ht, "Alice");
    printf("\nAfter deleting Alice:\n");
    display(ht);

    return 0;
}
