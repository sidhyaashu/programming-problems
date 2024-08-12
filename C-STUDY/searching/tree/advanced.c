/*
 Below are C language implementations for Depth-Limited Search (DLS), Iterative Deepening Depth-First Search (IDDFS), and finding the diameter of a binary tree.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CHILDREN 10 // Maximum number of children a node can have

// Node structure for the binary tree
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Depth-Limited Search (DLS)
bool depthLimitedSearch(TreeNode* node, int goal, int depthLimit) {
    if (node == NULL)
        return false;
    if (node->val == goal)
        return true;
    if (depthLimit <= 0)
        return false;
    
    // Recursive calls for children
    return depthLimitedSearch(node->left, goal, depthLimit - 1) || 
           depthLimitedSearch(node->right, goal, depthLimit - 1);
}

// Iterative Deepening Depth-First Search (IDDFS)
bool iterativeDeepeningDFS(TreeNode* root, int goal) {
    int depthLimit = 0;
    while (true) {
        if (depthLimitedSearch(root, goal, depthLimit))
            return true;
        depthLimit++;
    }
}

// Function to find the height of the binary tree
int height(TreeNode* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the diameter of the binary tree
int diameter(TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    
    return (leftHeight + rightHeight + 1 > leftDiameter && leftHeight + rightHeight + 1 > rightDiameter) ? 
           leftHeight + rightHeight + 1 : 
           (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
}

int main() {
    // Constructing the binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Example usage of IDDFS
    int goal = 5;
    printf("Node %d is found using IDDFS: %s\n", goal, iterativeDeepeningDFS(root, goal) ? "True" : "False");

    // Example usage of diameter calculation
    printf("Diameter of the binary tree: %d\n", diameter(root));

    // Clean up allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
