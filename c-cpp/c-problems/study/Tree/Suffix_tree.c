#include <stdio.h>
#include <stdlib.h>
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

// Function to print the Suffix Tree
void printSuffixTreeUtil(SuffixTreeNode *root, char *text) {
    if (root == NULL)
        return;
    if (root->start != -1) {
        printf("Suffix: ");
        for (int i = root->start; i <= *(root->end); i++)
            printf("%c", text[i]);
        printf("\n");
    }
    for (int i = 0; i < 256; i++)
        printSuffixTreeUtil(root->children[i], text);
}

// Function to construct the Suffix Tree
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

// Main function
int main() {
    char text[] = "banana";
    int n = strlen(text);

    // Construct the Suffix Tree
    SuffixTreeNode *root = buildSuffixTree(text, n);

    // Print the Suffix Tree
    printf("Suffix Tree for the text '%s':\n", text);
    printSuffixTreeUtil(root, text);

    // Free memory allocated for the Suffix Tree nodes
    freeSuffixTree(root);

    return 0;
}
