/*
We define a CustomSet class that encapsulates a binary search tree (BST).
It contains methods for insertion (insert), searching (search), deletion (erase), and traversal (inorderTraversal).
The nodes of the BST are implemented using a nested Node structure.
We also provide a destructor (~CustomSet()) and a helper function clear() to deallocate memory properly.

*/


#include <iostream>

template <typename T>
class CustomSet {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Private helper functions
    void insertHelper(Node*& node, const T& val) {
        if (node == nullptr) {
            node = new Node(val);
        } else if (val < node->data) {
            insertHelper(node->left, val);
        } else if (val > node->data) {
            insertHelper(node->right, val);
        }
    }

    bool searchHelper(Node* node, const T& val) const {
        if (node == nullptr) {
            return false;
        } else if (val == node->data) {
            return true;
        } else if (val < node->data) {
            return searchHelper(node->left, val);
        } else {
            return searchHelper(node->right, val);
        }
    }

    void inorderTraversalHelper(Node* node) const {
        if (node != nullptr) {
            inorderTraversalHelper(node->left);
            std::cout << node->data << " ";
            inorderTraversalHelper(node->right);
        }
    }

    Node* findMin(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void deleteNodeHelper(Node*& node, const T& val) {
        if (node == nullptr) {
            return;
        } else if (val < node->data) {
            deleteNodeHelper(node->left, val);
        } else if (val > node->data) {
            deleteNodeHelper(node->right, val);
        } else { // Found the node to delete
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                deleteNodeHelper(node->right, temp->data);
            }
        }
    }

public:
    CustomSet() : root(nullptr) {}

    void insert(const T& val) {
        insertHelper(root, val);
    }

    bool search(const T& val) const {
        return searchHelper(root, val);
    }

    void erase(const T& val) {
        deleteNodeHelper(root, val);
    }

    void inorderTraversal() const {
        inorderTraversalHelper(root);
        std::cout << std::endl;
    }

    bool empty() const {
        return root == nullptr;
    }

    // Destructor to free memory
    ~CustomSet() {
        clear(root);
    }

    // Helper function for destructor
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

int main() {
    CustomSet<int> mySet;
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(2); // Ignored, as it's already present
    std::cout << "Searching for 5: " << (mySet.search(5) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 3: " << (mySet.search(3) ? "Found" : "Not Found") << std::endl;
    mySet.erase(2);
    mySet.inorderTraversal();
    return 0;
}
