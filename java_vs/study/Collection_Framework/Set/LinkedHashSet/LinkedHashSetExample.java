package Collection_Framework.Set.LinkedHashSet;

/*
LinkedHashSet<String> linkedHashSet = new LinkedHashSet<>();: Creates a new instance of LinkedHashSet.
linkedHashSet.add("Apple");: Adds the element "Apple" to the LinkedHashSet.
System.out.println("LinkedHashSet elements: " + linkedHashSet);: Prints the elements of the LinkedHashSet.
System.out.println("Size of LinkedHashSet: " + linkedHashSet.size());: Prints the size of the LinkedHashSet.
System.out.println("Is 'Banana' present? " + linkedHashSet.contains("Banana"));: Checks if the element "Banana" is present in the LinkedHashSet.
linkedHashSet.remove("Orange");: Removes the element "Orange" from the LinkedHashSet.
Iterator<String> iterator = linkedHashSet.iterator();: Creates an Iterator to iterate over the elements of the LinkedHashSet.
while (iterator.hasNext()) { System.out.println(iterator.next()); }: Iterates over the elements of the LinkedHashSet using the Iterator and prints each element.
linkedHashSet.clear();: Clears all the elements from the LinkedHashSet.
System.out.println("Is LinkedHashSet empty? " + linkedHashSet.isEmpty());: Checks if the LinkedHashSet is empty.
 */
import java.util.LinkedHashSet;
import java.util.Iterator;

public class LinkedHashSetExample {
    public static void main(String[] args) {
        // Creating a LinkedHashSet
        LinkedHashSet<String> linkedHashSet = new LinkedHashSet<>();

        // Adding elements to the LinkedHashSet
        linkedHashSet.add("Apple");
        linkedHashSet.add("Banana");
        linkedHashSet.add("Orange");

        // Displaying the elements of the LinkedHashSet
        System.out.println("LinkedHashSet elements: " + linkedHashSet);

        // Size of the LinkedHashSet
        System.out.println("Size of LinkedHashSet: " + linkedHashSet.size());

        // Checking if an element is present
        System.out.println("Is 'Banana' present? " + linkedHashSet.contains("Banana"));

        // Removing an element
        linkedHashSet.remove("Orange");
        System.out.println("After removing 'Orange', LinkedHashSet: " + linkedHashSet);

        // Iterating over the LinkedHashSet using Iterator
        System.out.println("Iterating over LinkedHashSet using Iterator:");
        Iterator<String> iterator = linkedHashSet.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        // Clearing the LinkedHashSet
        linkedHashSet.clear();
        System.out.println("LinkedHashSet after clearing: " + linkedHashSet);
        
        // Checking if LinkedHashSet is empty
        System.out.println("Is LinkedHashSet empty? " + linkedHashSet.isEmpty());
    }
}
