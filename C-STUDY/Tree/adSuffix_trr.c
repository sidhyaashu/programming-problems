#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for a Suffix Tree node
typedef struct SuffixTreeNode {
    struct SuffixTreeNode *children[256];
    int start;
    int *end;
    struct SuffixTreeNode *suffixLink;
} SuffixTreeNode;

// Function to create a new Suffix Tree node
SuffixTreeNode *createNode(int start, int *end) {
    SuffixTreeNode *node = (SuffixTreeNode *)malloc(sizeof(SuffixTreeNode));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < 256; i++)
        node->children[i] = NULL;
    node->start = start;
    node->end = end;
    node->suffixLink = NULL;
    return node;
}

// Function to add a suffix to the Suffix Tree
void addSuffix(SuffixTreeNode *root, char *suffix, int *end) {
    SuffixTreeNode *current = root;
    for (int i = 0; suffix[i] != '\0'; i++) {
        if (current->children[suffix[i]] == NULL)
            current->children[suffix[i]] = createNode(i, end);
        current = current->children[suffix[i]];
    }
}

// Function to build the Suffix Tree
SuffixTreeNode *buildSuffixTree(char *text, int n) {
    SuffixTreeNode *root = createNode(-1, NULL);
    for (int i = 0; i < n; i++) {
        int *end = (int *)malloc(sizeof(int));
        *end = i;
        addSuffix(root, text + i, end);
    }
    return root;
}

// Function to free memory allocated for the Suffix Tree nodes
void freeSuffixTree(SuffixTreeNode *root) {
    if (root == NULL)
        return;
    for (int i = 0; i < 256; i++)
        freeSuffixTree(root->children[i]);
    free(root->end);
    free(root);
}

// Function to search for a pattern in the Suffix Tree
void searchPattern(SuffixTreeNode *root, char *pattern, char *text) {
    SuffixTreeNode *current = root;
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (current->children[pattern[i]] == NULL) {
            printf("Pattern '%s' not found in the text.\n", pattern);
            return;
        }
        current = current->children[pattern[i]];
    }
    printf("Pattern '%s' found at position(s): ", pattern);
    int startPos = current->start - strlen(pattern) + 1;
    int endPos = *(current->end);
    for (int i = startPos; i <= endPos; i++)
        printf("%d ", i);
    printf("\n");
}

// Function to find the longest common substring between the text and its reverse
void longestCommonSubstring(SuffixTreeNode *root, char *text) {
    // Find the deepest internal node (not leaf) with at least two children
    SuffixTreeNode *deepestInternal = NULL;
    for (int i = 0; i < 256; i++) {
        if (root->children[i] != NULL && root->children[i]->children['$'] != NULL) {
            deepestInternal = root->children[i];
            break;
        }
    }
    if (deepestInternal == NULL) {
        printf("No common substring found.\n");
        return;
    }
    // Output the common substring
    printf("Longest common substring: ");
    for (int i = deepestInternal->start; i <= *(deepestInternal->end); i++)
        printf("%c", text[i]);
    printf("\n");
}

// Function to find the longest repeated substring in the text
void longestRepeatedSubstring(SuffixTreeNode *root, char *text) {
    // Find the deepest node with at least two descendants
    SuffixTreeNode *deepestNode = NULL;
    for (int i = 0; i < 256; i++) {
        if (root->children[i] != NULL && root->children[i]->children['$'] != NULL) {
            deepestNode = root->children[i];
            break;
        }
    }
    if (deepestNode == NULL) {
        printf("No repeated substring found.\n");
        return;
    }
    // Output the longest repeated substring
    printf("Longest repeated substring: ");
    for (int i = deepestNode->start; i <= *(deepestNode->end); i++)
        printf("%c", text[i]);
    printf("\n");
}

// Function to search for multiple patterns in the text
void searchMultiplePatterns(SuffixTreeNode *root, char *patterns[], int numPatterns, char *text) {
    for (int i = 0; i < numPatterns; i++)
        searchPattern(root, patterns[i], text);
}

// Main function
int main() {
    char text[] = "banana";
    int n = strlen(text);

    // Construct the Suffix Tree
    SuffixTreeNode *root = buildSuffixTree(text, n);

    // Perform advanced operations
    char *patterns[] = {"an", "na"};
    int numPatterns = sizeof(patterns) / sizeof(patterns[0]);
    searchMultiplePatterns(root, patterns, numPatterns, text);
    longestCommonSubstring(root, text);
    longestRepeatedSubstring(root, text);

    // Free memory allocated for the Suffix Tree nodes
    freeSuffixTree(root);

    return 0;
}
