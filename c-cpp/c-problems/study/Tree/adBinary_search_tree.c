#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a BST node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new BST node
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

// Function to insert a node into the BST
TreeNode *insert(TreeNode *root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find the kth smallest element in the BST
void kthSmallestUtil(TreeNode *root, int k, int *count, int *result) {
    if (root == NULL || *count >= k)
        return;
    kthSmallestUtil(root->left, k, count, result);
    (*count)++;
    if (*count == k)
        *result = root->data;
    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(TreeNode *root, int k) {
    int count = 0, result = -1;
    kthSmallestUtil(root, k, &count, &result);
    return result;
}

// Function to find the lowest common ancestor of two nodes in the BST
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}

// Function to check if a tree is a valid BST
bool isValidBSTUtil(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (root == NULL)
        return true;
    if ((min != NULL && root->data <= min->data) || (max != NULL && root->data >= max->data))
        return false;
    return isValidBSTUtil(root->left, min, root) && isValidBSTUtil(root->right, root, max);
}

bool isValidBST(TreeNode *root) {
    return isValidBSTUtil(root, NULL, NULL);
}

// Function to convert a BST to a sorted doubly linked list
TreeNode *prev = NULL;
TreeNode *head = NULL;

void convertToDLL(TreeNode *root) {
    if (root == NULL)
        return;
    convertToDLL(root->left);
    if (prev == NULL)
        head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertToDLL(root->right);
}

// Function to print the doubly linked list
void printDLL(TreeNode *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->right;
    }
}

// Main function
int main() {
    TreeNode *root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Find the kth smallest element
    int k = 3;
    printf("The %dth smallest element is: %d\n", k, kthSmallest(root, k));

    // Find the lowest common ancestor of two nodes
    TreeNode *p = root->left->left;  // Node with value 20
    TreeNode *q = root->left->right; // Node with value 40
    TreeNode *lca = lowestCommonAncestor(root, p, q);
    printf("Lowest common ancestor of %d and %d is: %d\n", p->data, q->data, lca->data);

    // Check if the tree is a valid BST
    printf("Is the tree a valid BST? %s\n", isValidBST(root) ? "Yes" : "No");

    // Convert the BST to a sorted doubly linked list
    convertToDLL(root);
    printf("Sorted doubly linked list: ");
    printDLL(head);
    printf("\n");

    // Free memory allocated for the BST nodes
    // This step is optional since the program ends here
    return 0;
}
