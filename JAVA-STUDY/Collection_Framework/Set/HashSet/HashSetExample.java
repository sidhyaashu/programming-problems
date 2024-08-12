/*
Creation: HashSet<String> hashSet = new HashSet<>(); - Creates a new instance of HashSet to store strings.
Adding elements: hashSet.add("Apple"); - Adds elements to the HashSet.
Displaying elements: System.out.println("HashSet elements: " + hashSet); - Prints the elements of the HashSet.
Size: System.out.println("Size of HashSet: " + hashSet.size()); - Prints the number of elements in the HashSet.
Empty check: System.out.println("Is HashSet empty? " + hashSet.isEmpty()); - Checks if the HashSet is empty.
Adding duplicate element: hashSet.add("Apple"); - Demonstrates that HashSet doesn't allow duplicate elements.
Removing element: hashSet.remove("Banana"); - Removes a specified element from the HashSet.
Checking element existence: System.out.println("Is 'Apple' present in HashSet? " + hashSet.contains("Apple")); - Checks if a specific element is present in the HashSet.
Iteration: Uses an iterator to traverse through the elements of the HashSet and prints them.
Clearing the HashSet: hashSet.clear(); - Removes all elements from the HashSet.
 */

import java.util.HashSet;
import java.util.Iterator;

public class HashSetExample {
    public static void main(String[] args) {
        // Creating a HashSet
        HashSet<String> hashSet = new HashSet<>();

        // Adding elements to the HashSet
        hashSet.add("Apple");
        hashSet.add("Banana");
        hashSet.add("Orange");

        // Displaying the HashSet
        System.out.println("HashSet elements: " + hashSet);

        // Size of the HashSet
        System.out.println("Size of HashSet: " + hashSet.size());

        // Checking if the HashSet is empty
        System.out.println("Is HashSet empty? " + hashSet.isEmpty());

        // Adding duplicate element
        hashSet.add("Apple");
        System.out.println("HashSet after adding duplicate element: " + hashSet);

        // Removing an element
        hashSet.remove("Banana");
        System.out.println("HashSet after removing 'Banana': " + hashSet);

        // Checking if an element is present
        System.out.println("Is 'Apple' present in HashSet? " + hashSet.contains("Apple"));

        // Iterating through the HashSet
        System.out.println("Iterating through the HashSet:");
        Iterator<String> iterator = hashSet.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        // Clearing the HashSet
        hashSet.clear();
        System.out.println("HashSet after clearing: " + hashSet);
    }
}
