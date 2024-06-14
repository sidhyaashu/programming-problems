/*
In C language, there isn't a built-in hashmap data structure like in higher-level languages such as Java or Python. However, you can implement a hashmap yourself using arrays and linked lists (for handling collisions) or using other techniques. Below, I'll outline the concept of a hashmap in C and provide some basic operations along with code examples.

*/

/*
A hashmap is a data structure that stores key-value pairs. It provides efficient insertion, deletion, and lookup operations. The basic idea is to use a hash function to map keys to indices in an array, where the values associated with those keys are stored.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10

// Define the structure for a hashmap node
typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

// Define the hashmap structure
typedef struct {
    Node *array[HASH_SIZE];
} Hashmap;

// Hash function
int hash(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % HASH_SIZE;
}

// Initialization function
Hashmap* createHashmap() {
    Hashmap *hashmap = (Hashmap*)malloc(sizeof(Hashmap));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashmap->array[i] = NULL;
    }
    return hashmap;
}

// Insertion function
void insert(Hashmap *hashmap, char *key, int value) {
    int index = hash(key);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;

    if (hashmap->array[index] == NULL) {
        hashmap->array[index] = newNode;
    } else {
        Node *current = hashmap->array[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Search function
int search(Hashmap *hashmap, char *key) {
    int index = hash(key);
    Node *current = hashmap->array[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

// Deletion function
void delete(Hashmap *hashmap, char *key) {
    int index = hash(key);
    Node *current = hashmap->array[index];
    Node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                hashmap->array[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Main function for testing
int main() {
    Hashmap *hashmap = createHashmap();

    insert(hashmap, "apple", 5);
    insert(hashmap, "banana", 10);
    insert(hashmap, "orange", 15);

    printf("Value of apple: %d\n", search(hashmap, "apple"));
    printf("Value of banana: %d\n", search(hashmap, "banana"));
    printf("Value of orange: %d\n", search(hashmap, "orange"));

    delete(hashmap, "banana");

    printf("Value of banana after deletion: %d\n", search(hashmap, "banana"));

    return 0;
}
