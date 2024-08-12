/*
We added lowerBound and upperBound methods to find the lower and upper bounds of a value respectively.
rangeErase method is added to erase all elements in the set that fall within a specified range.
Advanced operations are demonstrated in the main() function.

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

    Node* lowerBoundHelper(Node* node, const T& val) const {
        if (node == nullptr) {
            return nullptr;
        } else if (val == node->data) {
            return node;
        } else if (val < node->data) {
            Node* left = lowerBoundHelper(node->left, val);
            return (left != nullptr) ? left : node;
        } else {
            return lowerBoundHelper(node->right, val);
        }
    }

    Node* upperBoundHelper(Node* node, const T& val) const {
        if (node == nullptr) {
            return nullptr;
        } else if (val < node->data) {
            Node* right = upperBoundHelper(node->left, val);
            return (right != nullptr) ? right : node;
        } else {
            return upperBoundHelper(node->right, val);
        }
    }

    void rangeEraseHelper(Node*& node, const T& start, const T& end) {
        if (node == nullptr) {
            return;
        }
        if (node->data < start) {
            rangeEraseHelper(node->right, start, end);
        } else if (node->data > end) {
            rangeEraseHelper(node->left, start, end);
        } else {
            deleteNodeHelper(node, node->data);
            rangeEraseHelper(node, start, end);
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

    Node* lowerBound(const T& val) const {
        return lowerBoundHelper(root, val);
    }

    Node* upperBound(const T& val) const {
        return upperBoundHelper(root, val);
    }

    void rangeErase(const T& start, const T& end) {
        rangeEraseHelper(root, start, end);
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

    // Advanced operations
    CustomSet<int>::Node* lowerBoundNode = mySet.lowerBound(3);
    if (lowerBoundNode != nullptr) {
        std::cout << "Lower Bound of 3: " << lowerBoundNode->data << std::endl;
    } else {
        std::cout << "Lower Bound of 3 not found" << std::endl;
    }

    CustomSet<int>::Node* upperBoundNode = mySet.upperBound(5);
    if (upperBoundNode != nullptr) {
        std::cout << "Upper Bound of 5: " << upperBoundNode->data << std::endl;
    } else {
        std::cout << "Upper Bound of 5 not found" << std::endl;
    }

    // Range erase
    mySet.rangeErase(3, 7);
    mySet.inorderTraversal();

    return 0;
}
