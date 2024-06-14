#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

// Define structure for hash node
struct hash_node {
    char *key;
    int value;
    struct hash_node *next;
};

// Define structure for hash table
struct hash_table {
    struct hash_node *table[TABLE_SIZE];
};

// Function to create a new hash table
struct hash_table* create_hash_table() {
    struct hash_table *new_table = (struct hash_table*)malloc(sizeof(struct hash_table));
    for (int i = 0; i < TABLE_SIZE; i++) {
        new_table->table[i] = NULL;
    }
    return new_table;
}

// Function to generate hash value for a given key
int hash_function(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash << 5) + key[i];
    }
    return hash % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct hash_table *ht, char *key, int value) {
    int index = hash_function(key);
    struct hash_node *new_node = (struct hash_node*)malloc(sizeof(struct hash_node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        // Handle collisions by chaining
        struct hash_node *temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to search for a key in the hash table
int search(struct hash_table *ht, char *key) {
    int index = hash_function(key);
    struct hash_node *temp = ht->table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

int main() {
    struct hash_table *ht = create_hash_table();

    // Insert some key-value pairs
    insert(ht, "apple", 10);
    insert(ht, "banana", 20);
    insert(ht, "orange", 30);

    // Search for a key
    int value = search(ht, "banana");
    if (value != -1) {
        printf("Value for 'banana' is: %d\n", value);
    } else {
        printf("Key not found\n");
    }

    // Cleanup: Free allocated memory
    // (This is just a basic example, in real-world applications, proper memory management is important)
    // Free nodes in the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct hash_node *current = ht->table[i];
        while (current != NULL) {
            struct hash_node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    // Free the hash table itself
    free(ht);

    return 0;
}
