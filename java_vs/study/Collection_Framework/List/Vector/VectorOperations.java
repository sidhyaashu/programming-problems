package Collection_Framework.List.Vector;

/*
ArrayList<Integer> vector = new ArrayList<>();: Creates a new ArrayList (vector) to store Integer elements.

vector.add(5);: Adds the element 5 to the end of the vector.

vector.get(2);: Retrieves the element at index 2 from the vector.

vector.set(1, 100);: Replaces the element at index 1 with the value 100.

vector.remove(0);: Removes the element at index 0 from the vector.

vector.contains(15);: Checks if the vector contains the element 15.

vector.indexOf(20);: Finds the index of the element 20 in the vector.

Collections.sort(vector);: Sorts the elements of the vector in ascending order.

Collections.reverse(vector);: Reverses the order of elements in the vector.

vector.clear();: Removes all elements from the vector.
 */


 import java.util.ArrayList;
import java.util.Collections;

public class VectorOperations {
    public static void main(String[] args) {
        // Creating an ArrayList (Vector)
        ArrayList<Integer> vector = new ArrayList<>();

        // Adding elements to the vector
        vector.add(5);
        vector.add(10);
        vector.add(15);
        vector.add(20);

        // Printing the vector
        System.out.println("Vector elements: " + vector);

        // Accessing elements by index
        int elementAtIndex2 = vector.get(2);
        System.out.println("Element at index 2: " + elementAtIndex2);

        // Updating an element
        vector.set(1, 100);
        System.out.println("Updated vector: " + vector);

        // Removing an element
        vector.remove(0);
        System.out.println("Vector after removing first element: " + vector);

        // Checking if an element exists
        boolean contains15 = vector.contains(15);
        System.out.println("Does the vector contain 15? " + contains15);

        // Finding the index of an element
        int index = vector.indexOf(20);
        System.out.println("Index of element 20: " + index);

        // Sorting the vector
        Collections.sort(vector);
        System.out.println("Sorted vector: " + vector);

        // Reversing the vector
        Collections.reverse(vector);
        System.out.println("Reversed vector: " + vector);

        // Clearing the vector
        vector.clear();
        System.out.println("Vector after clearing: " + vector);
    }
}
