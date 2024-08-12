// By default cpp does not contains tree data structure but we can easily create
/*
The Node class represents a single node in the binary search tree, with data, left, and right pointers.
The BinarySearchTree class represents the binary search tree itself, with methods like insert, search, and inorderTraversal.
The insert method inserts a value into the tree while maintaining the BST property.
The search method searches for a value in the tree.
The inorderTraversal method performs an inorder traversal of the tree, printing the values in sorted order.
The main function demonstrates the usage of the BinarySearchTree class by inserting values into the tree, searching for values, and performing inorder traversal.
*/

#include <iostream>

// Node class represents a single node in the binary search tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class represents the binary search tree
class BinarySearchTree {
private:
    Node* root;

    // Helper method for inserting a node into the tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper method for searching a value in the tree
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Helper method for inorder traversal
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Method to insert a value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Method to search for a value in the tree
    bool search(int value) {
        return search(root, value);
    }

    // Method to perform inorder traversal of the tree
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert some values into the tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Search for a value in the tree
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;

    // Perform inorder traversal of the tree
    std::cout << "Inorder traversal: ";
    bst.inorderTraversal();

    return 0;
}
