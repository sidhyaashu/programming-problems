package Collection_Framework.List.LinkedList;

public class LinkedList {
    Node head;

    // Node class representing each element in the linked list
    class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    // Method to insert a new node at the beginning
    public void insertAtBeginning(int newData) {
        Node newNode = new Node(newData);
        newNode.next = head;
        head = newNode;
    }

    // Method to insert a new node at the end
    public void insertAtEnd(int newData) {
        Node newNode = new Node(newData);
        if (head == null) {
            head = newNode;
            return;
        }
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = newNode;
    }

    // Method to insert a new node at a given position
    public void insertAtPosition(int position, int newData) {
        if (position == 0) {
            insertAtBeginning(newData);
            return;
        }
        Node newNode = new Node(newData);
        Node current = head;
        for (int i = 0; current != null && i < position - 1; i++) {
            current = current.next;
        }
        if (current == null) {
            System.out.println("Position out of bounds");
            return;
        }
        newNode.next = current.next;
        current.next = newNode;
    }

    // Method to print the linked list
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    // Method to delete a node by value
    public void deleteNode(int key) {
        Node temp = head, prev = null;
        if (temp != null && temp.data == key) {
            head = temp.next;
            return;
        }
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Element not found");
            return;
        }
        prev.next = temp.next;
    }

    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();

        // Inserting elements into the linked list
        linkedList.insertAtEnd(1);
        linkedList.insertAtEnd(2);
        linkedList.insertAtEnd(3);
        linkedList.insertAtEnd(4);
        linkedList.insertAtBeginning(0);

        // Printing the linked list
        System.out.println("Linked List:");
        linkedList.printList();

        // Inserting an element at a specific position
        linkedList.insertAtPosition(3, 10);

        // Printing the linked list after insertion
        System.out.println("Linked List after insertion:");
        linkedList.printList();

        // Deleting an element from the linked list
        linkedList.deleteNode(3);

        // Printing the updated linked list
        System.out.println("Linked List after deletion:");
        linkedList.printList();
    }
}

