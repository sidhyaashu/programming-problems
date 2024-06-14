/*
We create an ArrayList of Strings.
We add elements to the ArrayList using the add method.
We display the ArrayList using System.out.println.
We access elements by index using the get method.
We update an element at a specific index using the set method.
We remove an element by index using the remove method.
We check if a specific element exists in the ArrayList using the contains method.
We get the size of the ArrayList using the size method.
We clear the ArrayList using the clear method.
We check if the ArrayList is empty using the isEmpty method.
 */


package Collection_Framework.List.ArrayList;

import java.util.ArrayList;

public class ArrayListOperations {
    public static void main(String[] args) {
        // Creating an ArrayList
        ArrayList<String> arrayList = new ArrayList<>();

        // Adding elements to the ArrayList
        arrayList.add("Apple");
        arrayList.add("Banana");
        arrayList.add("Orange");
        arrayList.add("Grapes");

        // Displaying the ArrayList
        System.out.println("ArrayList: " + arrayList);

        // Accessing elements by index
        String firstElement = arrayList.get(0);
        System.out.println("First element: " + firstElement);

        // Updating an element
        arrayList.set(2, "Mango");
        System.out.println("Updated ArrayList: " + arrayList);

        // Removing an element by index
        arrayList.remove(1);
        System.out.println("ArrayList after removing an element: " + arrayList);

        // Checking if an element exists
        boolean containsBanana = arrayList.contains("Banana");
        System.out.println("ArrayList contains 'Banana': " + containsBanana);

        // Getting the size of the ArrayList
        int size = arrayList.size();
        System.out.println("Size of ArrayList: " + size);

        // Clearing the ArrayList
        arrayList.clear();
        System.out.println("ArrayList after clearing: " + arrayList);

        // Checking if the ArrayList is empty
        boolean isEmpty = arrayList.isEmpty();
        System.out.println("Is ArrayList empty? " + isEmpty);
    }
}
