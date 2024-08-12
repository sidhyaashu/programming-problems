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

void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        for (int i = 0; i < root->numChildren; ++i) {
            preOrderTraversal(root->children[i]);
        }
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numChildren; ++i) {
            postOrderTraversal(root->children[i]);
        }
        printf("%d ", root->data);
    }
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        if (root->numChildren >= 1) {
            inOrderTraversal(root->children[0]);
        }
        printf("%d ", root->data);
        for (int i = 1; i < root->numChildren; ++i) {
            inOrderTraversal(root->children[i]);
        }
    }
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    struct TreeNode* left = lowestCommonAncestor(root->children[0], p, q);
    struct TreeNode* right = lowestCommonAncestor(root->children[1], p, q);
    if (left != NULL && right != NULL) {
        return root;
    }
    return (left != NULL) ? left : right;
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

    // Traversing the tree
    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Finding lowest common ancestor
    struct TreeNode* lca = lowestCommonAncestor(root, node4, node5);
    printf("Lowest Common Ancestor of 4 and 5: %d\n", lca->data);

    // Freeing memory
    free(root);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}
