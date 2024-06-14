#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Structure for a Prefix Tree node
typedef struct PrefixTreeNode {
    struct PrefixTreeNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int count; // Count of words sharing the prefix up to this node
} PrefixTreeNode;

// Function to create a new Prefix Tree node
PrefixTreeNode *createNode() {
    PrefixTreeNode *node = (PrefixTreeNode *)malloc(sizeof(PrefixTreeNode));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    node->isEndOfWord = false;
    node->count = 0;
    return node;
}

// Function to insert a word into the Prefix Tree
void insert(PrefixTreeNode *root, const char *word) {
    PrefixTreeNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL)
            current->children[index] = createNode();
        current = current->children[index];
        current->count++; // Increment count for each node visited
    }
    current->isEndOfWord = true;
}

// Function to search for a prefix in the Prefix Tree
bool searchPrefix(PrefixTreeNode *root, const char *prefix) {
    PrefixTreeNode *current = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL)
            return false; // Prefix not found
        current = current->children[index];
    }
    return true; // Prefix found
}

// Function to find all strings with a given prefix
void findAllWithPrefix(PrefixTreeNode *root, const char *prefix, char *buffer, int depth) {
    PrefixTreeNode *current = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL)
            return; // Prefix not found
        current = current->children[index];
    }
    // Traverse subtree to find all strings with the given prefix
    if (current->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (current->children[i] != NULL) {
            buffer[depth] = i + 'a';
            findAllWithPrefix(current->children[i], prefix, buffer, depth + 1);
        }
    }
}

// Function to find the longest common prefix among a set of strings
char *longestCommonPrefix(char *strs[], int n) {
    if (n == 0)
        return "";
    int minLen = strlen(strs[0]);
    for (int i = 1; i < n; i++) {
        int len = strlen(strs[i]);
        if (len < minLen)
            minLen = len;
    }
    char *result = (char *)malloc((minLen + 1) * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    int i, j;
    for (i = 0; i < minLen; i++) {
        char current = strs[0][i];
        for (j = 1; j < n; j++) {
            if (strs[j][i] != current)
                break;
        }
        if (j != n)
            break;
        result[i] = current;
    }
    result[i] = '\0';
    return result;
}

// Function to find the shortest unique prefix for each string in a set
void shortestUniquePrefix(char *strs[], int n) {
    PrefixTreeNode *root = createNode();
    // Insert all strings into the Prefix Tree
    for (int i = 0; i < n; i++)
        insert(root, strs[i]);
    // Traverse the tree to find the shortest unique prefix for each string
    for (int i = 0; i < n; i++) {
        PrefixTreeNode *current = root;
        char *prefix = (char *)malloc((strlen(strs[i]) + 1) * sizeof(char));
        if (prefix == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        int j;
        for (j = 0; strs[i][j] != '\0'; j++) {
            int index = strs[i][j] - 'a';
            prefix[j] = strs[i][j];
            if (current->children[index]->count == 1)
                break;
            current = current->children[index];
        }
        prefix[j + 1] = '\0';
        printf("%s\n", prefix);
        free(prefix);
    }
    free(root);
}

// Main function
int main() {
    char *words[] = {"apple", "app", "application", "banana", "ball"};
    int n = sizeof(words) / sizeof(words[0]);

    // Construct the Prefix Tree and perform operations
    PrefixTreeNode *root = createNode();
    for (int i = 0; i < n; i++)
        insert(root, words[i]);

    printf("All strings with prefix 'app':\n");
    findAllWithPrefix(root, "app", (char *)malloc(100 * sizeof(char)), 0);

    printf("\nLongest common prefix: %s\n", longestCommonPrefix(words, n));

    printf("\nShortest unique prefix for each string:\n");
    shortestUniquePrefix(words, n);

    // Free memory allocated for the Prefix Tree nodes
    // This step is optional since the program ends here
    return 0;
}
