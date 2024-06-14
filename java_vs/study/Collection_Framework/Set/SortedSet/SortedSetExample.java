package Collection_Framework.Set.SortedSet;

import java.util.*;

public class SortedSetExample {
    public static void main(String[] args) {
        // Creating a SortedSet
        SortedSet<String> sortedSet = new TreeSet<>();

        // Adding elements to the SortedSet
        sortedSet.add("Apple");
        sortedSet.add("Banana");
        sortedSet.add("Mango");
        sortedSet.add("Orange");

        // Displaying the elements of the SortedSet
        System.out.println("SortedSet elements: " + sortedSet);

        // Adding duplicate element
        sortedSet.add("Apple");

        // Displaying the elements after adding a duplicate
        System.out.println("SortedSet elements after adding a duplicate: " + sortedSet);

        // Removing an element
        sortedSet.remove("Banana");

        // Displaying the elements after removing an element
        System.out.println("SortedSet elements after removing an element: " + sortedSet);

        // Checking if an element exists
        System.out.println("Is Mango present in the SortedSet? " + sortedSet.contains("Mango"));

        // Getting the first element
        System.out.println("First element of the SortedSet: " + sortedSet.first());

        // Getting the last element
        System.out.println("Last element of the SortedSet: " + sortedSet.last());

        // Getting a subset of the SortedSet
        SortedSet<String> subSet = sortedSet.subSet("Apple", "Orange");
        System.out.println("Subset of the SortedSet: " + subSet);

        // Headset of the SortedSet
        SortedSet<String> headSet = sortedSet.headSet("Mango");
        System.out.println("HeadSet of the SortedSet: " + headSet);

        // Tailset of the SortedSet
        SortedSet<String> tailSet = sortedSet.tailSet("Mango");
        System.out.println("TailSet of the SortedSet: " + tailSet);

        // Clearing the SortedSet
        sortedSet.clear();

        // Displaying the elements after clearing
        System.out.println("SortedSet elements after clearing: " + sortedSet);

        // Checking if the SortedSet is empty
        System.out.println("Is SortedSet empty? " + sortedSet.isEmpty());

        // Getting the size of the SortedSet
        System.out.println("Size of the SortedSet: " + sortedSet.size());
    }
}
