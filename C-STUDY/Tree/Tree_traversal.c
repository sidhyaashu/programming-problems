#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new binary tree node
TreeNode *createNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Basic Pre-order traversal function
void basicPreorderTraversal(TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    basicPreorderTraversal(root->left);
    basicPreorderTraversal(root->right);
}

// Basic In-order traversal function
void basicInorderTraversal(TreeNode *root) {
    if (root == NULL)
        return;
    basicInorderTraversal(root->left);
    printf("%d ", root->data);
    basicInorderTraversal(root->right);
}

// Basic Post-order traversal function
void basicPostorderTraversal(TreeNode *root) {
    if (root == NULL)
        return;
    basicPostorderTraversal(root->left);
    basicPostorderTraversal(root->right);
    printf("%d ", root->data);
}

// Advanced Pre-order traversal function (with stack)
void advancedPreorderTraversal(TreeNode *root) {
    if (root == NULL)
        return;
    TreeNode *stack[100]; // Assuming the maximum size of the stack
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        TreeNode *current = stack[top--];
        printf("%d ", current->data);
        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Advanced In-order traversal function (with stack)
void advancedInorderTraversal(TreeNode *root) {
    if (root == NULL)
        return;
    TreeNode *stack[100]; // Assuming the maximum size of the stack
    int top = -1;
    TreeNode *current = root;
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Advanced Post-order traversal function (with two stacks)
void advancedPostorderTraversal(TreeNode *root) {
    if (root == NULL)
        return;
    TreeNode *stack1[100]; // Assuming the maximum size of the stack
    TreeNode *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        TreeNode *current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Main function
int main() {
    // Create a binary tree
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform basic traversals
    printf("Basic Pre-order traversal: ");
    basicPreorderTraversal(root);
    printf("\n");

    printf("Basic In-order traversal: ");
    basicInorderTraversal(root);
    printf("\n");

    printf("Basic Post-order traversal: ");
    basicPostorderTraversal(root);
    printf("\n");

    // Perform advanced traversals
    printf("Advanced Pre-order traversal: ");
    advancedPreorderTraversal(root);
    printf("\n");

    printf("Advanced In-order traversal: ");
    advancedInorderTraversal(root);
    printf("\n");

    printf("Advanced Post-order traversal: ");
    advancedPostorderTraversal(root);
    printf("\n");

    // Free memory allocated for the binary tree nodes
    // This step is optional since the program ends here
    return 0;
}
