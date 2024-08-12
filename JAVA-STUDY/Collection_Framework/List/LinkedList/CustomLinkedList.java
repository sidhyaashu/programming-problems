package Collection_Framework.List.LinkedList;

public class CustomLinkedList {
    // Node class representing each element in the linked list
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;

    // Constructor to initialize an empty linked list
    public CustomLinkedList() {
        this.head = null;
    }

    // Method to check if the linked list is empty
    public boolean isEmpty() {
        return head == null;
    }

    // Method to insert a new node at the beginning of the linked list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Method to insert a new node at the end of the linked list
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Method to print the elements of the linked list
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    // Method to delete the first occurrence of a node with given data
    public void delete(int key) {
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
            System.out.println("Element " + key + " not found");
            return;
        }
        prev.next = temp.next;
    }

    // Method to get the length of the linked list
    public int length() {
        int length = 0;
        Node current = head;
        while (current != null) {
            length++;
            current = current.next;
        }
        return length;
    }

    // Method to search for an element in the linked list
    public boolean search(int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public static void main(String[] args) {
        CustomLinkedList linkedList = new CustomLinkedList();

        // Inserting elements into the linked list
        linkedList.insertAtEnd(1);
        linkedList.insertAtEnd(2);
        linkedList.insertAtEnd(3);
        linkedList.insertAtEnd(4);
        linkedList.insertAtBeginning(0);

        // Printing the linked list
        System.out.println("Linked List:");
        linkedList.printList();

        // Deleting an element from the linked list
        linkedList.delete(3);

        // Printing the updated linked list
        System.out.println("Linked List after deletion:");
        linkedList.printList();

        // Length of the linked list
        System.out.println("Length of Linked List: " + linkedList.length());

        // Search for an element in the linked list
        int searchKey = 2;
        System.out.println("Is " + searchKey + " present in the list? " + linkedList.search(searchKey));
    }
}

