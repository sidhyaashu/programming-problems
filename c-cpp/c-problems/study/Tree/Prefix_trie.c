#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Function to create a new Trie node
struct TrieNode *createNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Function to insert a word into the Trie
void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL)
            current->children[index] = createNode();
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = true;
}

// Function to search for a word in the Trie
bool search(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL)
            return false;
        current = current->children[index];
        word++;
    }
    return (current != NULL && current->isEndOfWord);
}

// Function to delete a word from the Trie
bool deleteWord(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL)
            return false;
        current = current->children[index];
        word++;
    }
    if (current != NULL && current->isEndOfWord) {
        current->isEndOfWord = false;
        return true;
    }
    return false;
}

// Function to check if a Trie node has any children
bool hasChildren(struct TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL)
            return true;
    }
    return false;
}

// Function to recursively delete empty Trie nodes
bool deleteHelper(struct TrieNode *root, const char *word) {
    if (root == NULL)
        return false;
    if (*word) {
        int index = *word - 'a';
        if (root->children[index] != NULL && deleteHelper(root->children[index], word + 1)) {
            if (!hasChildren(root->children[index])) {
                free(root->children[index]);
                root->children[index] = NULL;
                return true;
            }
        }
    }
    return false;
}

// Main function
int main() {
    struct TrieNode *root = createNode();

    // Insert some words into the Trie
    insert(root, "apple");
    insert(root, "banana");
    insert(root, "orange");
    insert(root, "app");

    // Search for words in the Trie
    printf("Searching for 'apple': %s\n", search(root, "apple") ? "Found" : "Not found");
    printf("Searching for 'orange': %s\n", search(root, "orange") ? "Found" : "Not found");
    printf("Searching for 'grape': %s\n", search(root, "grape") ? "Found" : "Not found");

    // Delete a word from the Trie
    deleteWord(root, "apple");

    // Search again after deletion
    printf("Searching for 'apple' after deletion: %s\n", search(root, "apple") ? "Found" : "Not found");

    // Free memory allocated for the Trie nodes
    // This step is optional since the program ends here
    return 0;
}
