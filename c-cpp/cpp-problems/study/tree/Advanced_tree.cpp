/*
The findMin method finds the minimum value in the tree.
The findMax method finds the maximum value in the tree.
The height method calculates the height of the tree.
The levelOrderTraversal method performs level order traversal of the tree.
The remove method removes a node with a specified value from the tree while maintaining the BST property.
The preorderTraversal and postorderTraversal methods perform preorder and postorder traversal, respectively.
The main function demonstrates the usage of these additional methods.

*/

#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

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

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

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

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorderTraversal() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorderTraversal() {
        postorderTraversal(root);
        std::cout << std::endl;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    int findMin() {
        if (root == nullptr) {
            throw std::runtime_error("Tree is empty");
        }
        Node* minNode = findMin(root);
        return minNode->data;
    }

    int findMax() {
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

    int height() {
        return calculateHeight(root);
    }

    void levelOrderTraversal() {
        if (root == nullptr) {
            return;
        }
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->data << " ";
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
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

    // Perform different traversals
    std::cout << "Inorder traversal: ";
    bst.inorderTraversal();

    std::cout << "Preorder traversal: ";
    bst.preorderTraversal();

    std::cout << "Postorder traversal: ";
    bst.postorderTraversal();

    // Remove a value from the tree
    bst.remove(30);
    std::cout << "After removing 30, inorder traversal: ";
    bst.inorderTraversal();

    // Find minimum and maximum values in the tree
    std::cout << "Minimum value: " << bst.findMin() << std::endl;
    std::cout << "Maximum value: " << bst.findMax() << std::endl;

    // Calculate the height of the tree
    std::cout << "Height of the tree: " << bst.height() << std::endl;

    // Perform level order traversal
    std::cout << "Level order traversal: ";
    bst.levelOrderTraversal();

    return 0;
}
