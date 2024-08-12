#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a tree node
struct TreeNode {
    int value;
    int lazy;
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
    newNode->lazy = 0; // Initialize lazy propagation flag
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

// Function to propagate lazy updates
void propagateLazy(struct TreeNode* root) {
    if (root->lazy != 0) {
        root->value += (root->end - root->start + 1) * root->lazy;
        if (root->start != root->end) {
            root->left->lazy += root->lazy;
            root->right->lazy += root->lazy;
        }
        root->lazy = 0;
    }
}

// Function to perform a range query
int rangeQuery(struct TreeNode* root, int qs, int qe) {
    if (root == NULL || root->start > qe || root->end < qs)
        return 0;
    propagateLazy(root);
    if (qs <= root->start && qe >= root->end)
        return root->value;
    return rangeQuery(root->left, qs, qe) + rangeQuery(root->right, qs, qe);
}

// Function to update a range with a value
void rangeUpdate(struct TreeNode* root, int us, int ue, int diff) {
    propagateLazy(root);
    if (root == NULL || root->start > ue || root->end < us)
        return;
    if (us <= root->start && ue >= root->end) {
        root->value += (root->end - root->start + 1) * diff;
        if (root->start != root->end) {
            root->left->lazy += diff;
            root->right->lazy += diff;
        }
        return;
    }
    rangeUpdate(root->left, us, ue, diff);
    rangeUpdate(root->right, us, ue, diff);
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

    // Update range [1, 4] with a value of 2
    rangeUpdate(root, 1, 4, 2);

    // Perform query after update
    printf("Sum of elements in range [2, 5] after update = %d\n", rangeQuery(root, 2, 5));

    // Free memory allocated for the segment tree nodes
    // This step is optional since the program ends here
    return 0;
}
