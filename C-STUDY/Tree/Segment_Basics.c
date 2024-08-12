#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a tree node
struct TreeNode {
    int value;
    int start;
    int end;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int start, int end) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = 0; // Initialize with a default value
    newNode->start = start;
    newNode->end = end;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the segment tree
struct TreeNode* buildSegmentTree(int arr[], int start, int end) {
    if (start == end) {
        return createNode(start, end);
    }
    int mid = (start + end) / 2;
    struct TreeNode* root = createNode(start, end);
    root->left = buildSegmentTree(arr, start, mid);
    root->right = buildSegmentTree(arr, mid + 1, end);
    root->value = root->left->value + root->right->value;
    return root;
}

// Function to perform a range query
int rangeQuery(struct TreeNode* root, int qs, int qe) {
    if (root == NULL || root->start > qe || root->end < qs)
        return 0;
    if (qs <= root->start && qe >= root->end)
        return root->value;
    return rangeQuery(root->left, qs, qe) + rangeQuery(root->right, qs, qe);
}

// Function to update a value in the segment tree
void updateValue(struct TreeNode* root, int idx, int newVal) {
    if (root == NULL || idx < root->start || idx > root->end)
        return;
    if (root->start == idx && root->end == idx) {
        root->value = newVal;
        return;
    }
    updateValue(root->left, idx, newVal);
    updateValue(root->right, idx, newVal);
    root->value = root->left->value + root->right->value;
}

// Main function
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build the segment tree
    struct TreeNode* root = buildSegmentTree(arr, 0, n - 1);

    // Perform queries
    printf("Sum of elements in range [1, 3] = %d\n", rangeQuery(root, 1, 3));
    printf("Sum of elements in range [2, 5] = %d\n", rangeQuery(root, 2, 5));

    // Update value at index 3 to 10
    updateValue(root, 3, 10);

    // Perform query after update
    printf("Sum of elements in range [2, 5] after update = %d\n", rangeQuery(root, 2, 5));

    // Free memory allocated for the segment tree nodes
    // This step is optional since the program ends here
    return 0;
}
