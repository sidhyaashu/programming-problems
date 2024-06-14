package Collection_Framework.Set.SortedSet;

import java.util.*;

class CustomSortedSet<T extends Comparable<T>> {
    private class Node {
        T data;
        Node left, right;

        Node(T data) {
            this.data = data;
            left = right = null;
        }
    }

    private Node root;

    CustomSortedSet() {
        root = null;
    }

    // Add an element to the set
    public void add(T data) {
        root = insert(root, data);
    }

    private Node insert(Node root, T data) {
        if (root == null) {
            return new Node(data);
        }

        if (data.compareTo(root.data) < 0) {
            root.left = insert(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            root.right = insert(root.right, data);
        }
        return root;
    }

    // Check if an element exists in the set
    public boolean contains(T data) {
        return search(root, data);
    }

    private boolean search(Node root, T data) {
        if (root == null) {
            return false;
        }
        if (root.data.compareTo(data) == 0) {
            return true;
        } else if (root.data.compareTo(data) > 0) {
            return search(root.left, data);
        } else {
            return search(root.right, data);
        }
    }

    // Remove an element from the set
    public void remove(T data) {
        root = delete(root, data);
    }

    private Node delete(Node root, T data) {
        if (root == null) {
            return null;
        }

        if (data.compareTo(root.data) < 0) {
            root.left = delete(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            root.right = delete(root.right, data);
        } else {
            // Node to be deleted is found
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            root.data = findMin(root.right);
            root.right = delete(root.right, root.data);
        }
        return root;
    }

    private T findMin(Node root) {
        T min = root.data;
        while (root.left != null) {
            min = root.left.data;
            root = root.left;
        }
        return min;
    }

    // Get the first element of the set
    public T first() {
        if (root == null) {
            return null;
        }
        Node current = root;
        while (current.left != null) {
            current = current.left;
        }
        return current.data;
    }

    // Get the last element of the set
    public T last() {
        if (root == null) {
            return null;
        }
        Node current = root;
        while (current.right != null) {
            current = current.right;
        }
        return current.data;
    }

    // Clear the set
    public void clear() {
        root = null;
    }

    // Check if the set is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Get the size of the set
    public int size() {
        return getSize(root);
    }

    private int getSize(Node root) {
        if (root == null) {
            return 0;
        }
        return 1 + getSize(root.left) + getSize(root.right);
    }

    // Convert the set to a sorted array
    public Object[] toArray() {
        List<T> list = new ArrayList<>();
        inOrderTraversal(root, list);
        return list.toArray();
    }

    private void inOrderTraversal(Node root, List<T> list) {
        if (root != null) {
            inOrderTraversal(root.left, list);
            list.add(root.data);
            inOrderTraversal(root.right, list);
        }
    }

    // Get a subset of the set
    public CustomSortedSet<T> subSet(T fromElement, T toElement) {
        CustomSortedSet<T> subset = new CustomSortedSet<>();
        addSubset(root, subset, fromElement, toElement);
        return subset;
    }

    private void addSubset(Node root, CustomSortedSet<T> subset, T fromElement, T toElement) {
        if (root == null) {
            return;
        }

        if (root.data.compareTo(fromElement) > 0) {
            addSubset(root.left, subset, fromElement, toElement);
        }

        if (root.data.compareTo(fromElement) >= 0 && root.data.compareTo(toElement) <= 0) {
            subset.add(root.data);
        }

        if (root.data.compareTo(toElement) < 0) {
            addSubset(root.right, subset, fromElement, toElement);
        }
    }

    // Get a subset of the set less than the specified element
    public CustomSortedSet<T> headSet(T toElement) {
        CustomSortedSet<T> subset = new CustomSortedSet<>();
        addSubset(root, subset, null, toElement);
        return subset;
    }

    // Get a subset of the set greater than the specified element
    public CustomSortedSet<T> tailSet(T fromElement) {
        CustomSortedSet<T> subset = new CustomSortedSet<>();
        addSubset(root, subset, fromElement, null);
        return subset;
    }

    // Display the set
    public void display() {
        display(root);
    }

    private void display(Node root) {
        if (root != null) {
            display(root.left);
            System.out.print(root.data + " ");
            display(root.right);
        }
    }

    public static void main(String[] args) {
        // Creating a custom sorted set
        CustomSortedSet<Integer> sortedSet = new CustomSortedSet<>();

        // Adding elements to the set
        sortedSet.add(5);
        sortedSet.add(2);
        sortedSet.add(8);
        sortedSet.add(1);

        // Displaying the set
        System.out.print("SortedSet elements: ");
        sortedSet.display();
        System.out.println();

        // Checking if an element exists
        System.out.println("Is 5 present in the set? " + sortedSet.contains(5));

        // Removing an element
        sortedSet.remove(2);

        // Displaying the set after removal
        System.out.print("SortedSet elements after removing 2: ");
        sortedSet.display();
        System.out.println();

        // Getting the first and last elements
        System.out.println("First element: " + sortedSet.first());
        System.out.println("Last element: " + sortedSet.last());

        // Getting a subset of the set
        CustomSortedSet<Integer> subset = sortedSet.subSet(1, 5);
        System.out.print("Subset of the set: ");
        subset.display();
        System.out.println();

        // Getting a headSet of the set
        CustomSortedSet<Integer> headSet = sortedSet.headSet(5);
        System.out.print("HeadSet of the set: ");
        headSet.display();
        System.out.println();

        // Getting a tailSet of the set
        CustomSortedSet<Integer> tailSet = sortedSet.tailSet(2);
        System.out.print("TailSet of the set: ");
        tailSet.display();
        System.out.println();

        // Clearing the set
        sortedSet.clear();

        // Displaying the set after clearing
        System.out.print("SortedSet elements after clearing: ");
        sortedSet.display();
        System.out.println();

        // Checking if the set is empty
        System.out.println("Is the set empty? " + sortedSet.isEmpty());

        // Getting the size of the set
        System.out.println("Size of the set: " + sortedSet.size());
    }
}
