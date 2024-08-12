package Tree;
/*
Node: This nested static class represents each node in the binary tree. It contains fields for the node's key value, left child, and right child.
Main: This is the main class containing the binary tree operations. It includes methods for insertion (insert), three types of tree traversals (inorderTraversal, preorderTraversal, postorderTraversal), and searching (search).
insert(int key): This method inserts a new node with the given key value into the binary tree.
insertRec(Node root, int key): This is a recursive helper method used by insert to insert a new key into the binary tree.
inorderTraversal(Node root), preorderTraversal(Node root), postorderTraversal(Node root): These methods perform in-order, pre-order, and post-order traversals of the binary tree, respectively.
search(int key): This method searches for a given key in the binary tree.
searchRec(Node root, int key): This is a recursive helper method used by search to search for a key in the binary tree.
main: This is the entry point of the program. Inside this method, we create a binary tree object, insert elements into it, perform traversals, and search for an element in the tree. Finally, the results are printed to the console.
 */

public class Main {
    
    // Node class representing each node in the binary tree
    static class Node {
        int key;
        Node left, right;
        
        public Node(int item) {
            key = item;
            left = right = null;
        }
    }
    
    // Root of the Binary Tree
    Node root;
    
    // Constructor
    Main() {
        root = null;
    }
    
    // Method to insert a new node with the given key
    void insert(int key) {
        root = insertRec(root, key);
    }
    
    // A recursive function to insert a new key in BST
    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);
        
        return root;
    }
    
    // Method to perform in-order traversal of the tree
    void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.key + " ");
            inorderTraversal(root.right);
        }
    }
    
    // Method to perform pre-order traversal of the tree
    void preorderTraversal(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorderTraversal(root.left);
            preorderTraversal(root.right);
        }
    }
    
    // Method to perform post-order traversal of the tree
    void postorderTraversal(Node root) {
        if (root != null) {
            postorderTraversal(root.left);
            postorderTraversal(root.right);
            System.out.print(root.key + " ");
        }
    }
    
    // Method to search for a key in the tree
    boolean search(int key) {
        return searchRec(root, key);
    }
    
    // A recursive function to search for a key in the tree
    boolean searchRec(Node root, int key) {
        if (root == null)
            return false;
        
        if (root.key == key)
            return true;
        
        if (key < root.key)
            return searchRec(root.left, key);
        
        return searchRec(root.right, key);
    }
    
    // Main method
    public static void main(String[] args) {
        Main tree = new Main();
        
        // Inserting elements into the tree
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);
        
        // Printing in-order traversal
        System.out.println("In-order Traversal:");
        tree.inorderTraversal(tree.root);
        System.out.println();
        
        // Printing pre-order traversal
        System.out.println("Pre-order Traversal:");
        tree.preorderTraversal(tree.root);
        System.out.println();
        
        // Printing post-order traversal
        System.out.println("Post-order Traversal:");
        tree.postorderTraversal(tree.root);
        System.out.println();
        
        // Searching for elements
        int keyToSearch = 40;
        if (tree.search(keyToSearch))
            System.out.println(keyToSearch + " found in the tree.");
        else
            System.out.println(keyToSearch + " not found in the tree.");
    }
}

