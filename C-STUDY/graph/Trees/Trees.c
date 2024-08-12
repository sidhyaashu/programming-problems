/*
createNode() function creates a new tree node with the given data.
addChild() function adds a child node to a parent node.
printTree() function prints the structure of the tree.
countNodes() function counts the number of nodes in the tree.
height() function calculates the height of the tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct TreeNode {
    int data;
    struct TreeNode* children[MAX_VERTICES];
    int numChildren;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->numChildren = 0;
    return newNode;
}

void addChild(struct TreeNode* parent, struct TreeNode* child) {
    if (parent->numChildren < MAX_VERTICES) {
        parent->children[parent->numChildren++] = child;
    } else {
        printf("Maximum number of children reached.\n");
    }
}

void printTree(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        for (int i = 0; i < root->numChildren; ++i) {
            printf("%d ", root->children[i]->data);
        }
        printf("\n");
        for (int i = 0; i < root->numChildren; ++i) {
            printTree(root->children[i]);
        }
    }
}

int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int count = 1;
    for (int i = 0; i < root->numChildren; ++i) {
        count += countNodes(root->children[i]);
    }
    return count;
}

int height(struct TreeNode* root) {
    if (root == NULL)
        return -1;
    int maxHeight = -1;
    for (int i = 0; i < root->numChildren; ++i) {
        int childHeight = height(root->children[i]);
        if (childHeight > maxHeight)
            maxHeight = childHeight;
    }
    return maxHeight + 1;
}

int main() {
    // Creating a tree
    struct TreeNode* root = createNode(1);
    struct TreeNode* node2 = createNode(2);
    struct TreeNode* node3 = createNode(3);
    struct TreeNode* node4 = createNode(4);
    struct TreeNode* node5 = createNode(5);

    addChild(root, node2);
    addChild(root, node3);
    addChild(node2, node4);
    addChild(node3, node5);

    // Printing the tree
    printf("Tree Structure:\n");
    printTree(root);

    // Counting nodes
    printf("Number of nodes in the tree: %d\n", countNodes(root));

    // Finding height of the tree
    printf("Height of the tree: %d\n", height(root));

    // Freeing memory
    free(root);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}
