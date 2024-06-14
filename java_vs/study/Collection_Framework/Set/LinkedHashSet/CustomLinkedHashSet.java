package Collection_Framework.Set.LinkedHashSet;

/*
CustomLinkedHashSet: This class represents a custom implementation of LinkedHashSet. It maintains a HashMap for fast lookup and a doubly linked list to preserve insertion order.
add(T element): Adds an element to the set if it doesn't already exist.
remove(T element): Removes the specified element from the set.
contains(T element): Checks if the set contains the specified element.
size(): Returns the number of elements in the set.
isEmpty(): Checks if the set is empty.
clear(): Removes all elements from the set.
iterator(): Returns an iterator over the elements in the set.
Node: Represents a node in the doubly linked list.
LinkedHashSetIterator: Iterator implementation for iterating over the set.
main(): Demonstrates the usage of CustomLinkedHashSet by adding elements, removing elements, checking containment, clearing the set, and checking if the set is empty.

 */
import java.util.HashMap;
import java.util.Iterator;

public class CustomLinkedHashSet<T> {
    private HashMap<T, Node<T>> map;
    private Node<T> head;
    private Node<T> tail;

    // Constructor
    public CustomLinkedHashSet() {
        map = new HashMap<>();
        head = null;
        tail = null;
    }

    // Method to add an element to the set
    public void add(T element) {
        if (!map.containsKey(element)) {
            Node<T> newNode = new Node<>(element);
            map.put(element, newNode);
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }
    }

    // Method to remove an element from the set
    public void remove(T element) {
        if (map.containsKey(element)) {
            Node<T> nodeToRemove = map.get(element);
            if (nodeToRemove == head && nodeToRemove == tail) {
                head = null;
                tail = null;
            } else if (nodeToRemove == head) {
                head = head.next;
                head.prev = null;
            } else if (nodeToRemove == tail) {
                tail = tail.prev;
                tail.next = null;
            } else {
                nodeToRemove.prev.next = nodeToRemove.next;
                nodeToRemove.next.prev = nodeToRemove.prev;
            }
            map.remove(element);
        }
    }

    // Method to check if the set contains an element
    public boolean contains(T element) {
        return map.containsKey(element);
    }

    // Method to get the size of the set
    public int size() {
        return map.size();
    }

    // Method to check if the set is empty
    public boolean isEmpty() {
        return map.isEmpty();
    }

    // Method to clear the set
    public void clear() {
        map.clear();
        head = null;
        tail = null;
    }

    // Method to iterate over the set
    public Iterator<T> iterator() {
        return new LinkedHashSetIterator();
    }

    // Node class for doubly linked list
    private static class Node<T> {
        T data;
        Node<T> prev;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    // Iterator implementation for iterating over the set
    private class LinkedHashSetIterator implements Iterator<T> {
        private Node<T> current = head;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public T next() {
            T data = current.data;
            current = current.next;
            return data;
        }
    }

    public static void main(String[] args) {
        CustomLinkedHashSet<String> linkedHashSet = new CustomLinkedHashSet<>();

        // Adding elements to the set
        linkedHashSet.add("Apple");
        linkedHashSet.add("Banana");
        linkedHashSet.add("Orange");

        // Displaying the elements of the set
        System.out.println("LinkedHashSet elements: ");
        for (String element : linkedHashSet) {
            System.out.println(element);
        }

        // Size of the set
        System.out.println("Size of LinkedHashSet: " + linkedHashSet.size());

        // Checking if an element is present
        System.out.println("Is 'Banana' present? " + linkedHashSet.contains("Banana"));

        // Removing an element
        linkedHashSet.remove("Orange");
        System.out.println("After removing 'Orange', LinkedHashSet: ");
        for (String element : linkedHashSet) {
            System.out.println(element);
        }

        // Clearing the set
        linkedHashSet.clear();
        System.out.println("LinkedHashSet after clearing: ");
        for (String element : linkedHashSet) {
            System.out.println(element);
        }

        // Checking if set is empty
        System.out.println("Is LinkedHashSet empty? " + linkedHashSet.isEmpty());
    }
}
