/**
createNode:                 Creates a new node with the given value.
insert:                 Inserts a new node with the given value into the binary tree.
search:                 Searches for a value in the binary tree.
deleteNode:                 Deletes a node with the given value from the binary tree.
minValueNode:               Finds the node with the minimum value in the binary tree.
inorderTraversal:               Performs an inorder traversal of the binary tree.
preorderTraversal:              Performs a preorder traversal of the binary tree.
postorderTraversal:                 Performs a postorder traversal of the binary tree.
freeTree:               Frees memory allocated for the binary tree nodes.
main:               Demonstrates the usage of the above functions by creating a binary tree, 
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else {
        if (value <= root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

// Function to search for a value in the binary tree
struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to delete a node from the binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    } else if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to find the node with the minimum value in a binary tree
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to traverse the binary tree in inorder (left, root, right) manner
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in preorder (root, left, right) manner
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in postorder (left, right, root) manner
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to free memory allocated for the binary tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    // Insert some elements into the binary tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print traversals of the binary tree
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Search for a value in the binary tree
    int searchValue = 40;
    struct TreeNode* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("%d found in the binary tree.\n", searchValue);
    } else {
        printf("%d not found in the binary tree.\n", searchValue);
    }

    // Delete a node from the binary tree
    int deleteValue = 20;
    root = deleteNode(root, deleteValue);
    printf("Inorder traversal after deleting %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");

    // Free memory allocated for the binary tree nodes
    freeTree(root);

    return 0;
}
