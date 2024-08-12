/*
Tree Traversal: Traversing a tree involves visiting each node in the tree exactly once.
*/

// Tree node definition
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct TreeNode *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->
