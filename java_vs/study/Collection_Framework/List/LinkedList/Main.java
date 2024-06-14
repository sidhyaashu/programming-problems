package Collection_Framework.List.LinkedList;

import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        // Creating a LinkedList
        LinkedList<String> linkedList = new LinkedList<>();

        // Adding elements to the LinkedList
        linkedList.add("Apple");
        linkedList.add("Banana");
        linkedList.add("Orange");
        linkedList.add("Mango");

        // Printing the elements of the LinkedList
        System.out.println("LinkedList elements: " + linkedList);

        // Adding an element at the specified index
        linkedList.add(2, "Grapes");
        System.out.println("After adding Grapes at index 2: " + linkedList);

        // Removing an element at the specified index
        linkedList.remove(1);
        System.out.println("After removing element at index 1: " + linkedList);

        // Getting the element at the specified index
        String elementAtIndex = linkedList.get(3);
        System.out.println("Element at index 3: " + elementAtIndex);

        // Setting an element at the specified index
        linkedList.set(0, "Pineapple");
        System.out.println("After setting Pineapple at index 0: " + linkedList);

        // Checking if the LinkedList is empty
        boolean isEmpty = linkedList.isEmpty();
        System.out.println("Is the LinkedList empty? " + isEmpty);

        // Getting the index of the first occurrence of an element
        int indexOfMango = linkedList.indexOf("Mango");
        System.out.println("Index of Mango: " + indexOfMango);

        // Getting the index of the last occurrence of an element
        int lastIndexOfMango = linkedList.lastIndexOf("Mango");
        System.out.println("Last Index of Mango: " + lastIndexOfMango);

        // Removing the first occurrence of a specified element
        boolean removed = linkedList.remove("Orange");
        System.out.println("Removed Orange? " + removed);
        System.out.println("After removing Orange: " + linkedList);

        // Removing all occurrences of a specified element
        linkedList.add("Banana");
        linkedList.add("Banana");
        linkedList.add("Banana");
        boolean removedAll = linkedList.removeAll(java.util.Collections.singleton("Banana"));
        System.out.println("Removed all occurrences of Banana? " + removedAll);
        System.out.println("After removing all occurrences of Banana: " + linkedList);

        // Reversing the LinkedList
        java.util.Collections.reverse(linkedList);
        System.out.println("Reversed LinkedList: " + linkedList);

        // Clearing the LinkedList
        linkedList.clear();
        System.out.println("LinkedList after clearing: " + linkedList);
    }
}
