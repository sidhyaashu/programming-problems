/*
add(int element): Adds an element to the end of the vector.
get(int index): Retrieves the element at the specified index.
set(int index, int element): Replaces the element at the specified index with the specified element.
remove(int index): Removes the element at the specified index.
size(): Returns the number of elements in the vector.
isEmpty(): Returns true if the vector contains no elements.
contains(int element): Returns true if the vector contains the specified element.
clear(): Removes all elements from the vector.
ensureCapacity(): Increases the capacity of the vector if necessary to ensure that it can hold at least the number of elements specified by the minimum capacity argument.
 */


package Collection_Framework.List.Vector;

import java.util.Arrays;

public class CustomVector {
    private static final int DEFAULT_CAPACITY = 10;
    private int[] array;
    private int size;

    // Constructor
    public CustomVector() {
        array = new int[DEFAULT_CAPACITY];
        size = 0;
    }

    // Add element to the end of the vector
    public void add(int element) {
        ensureCapacity();
        array[size++] = element;
    }

    // Get element at specified index
    public int get(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of range");
        return array[index];
    }

    // Set element at specified index
    public void set(int index, int element) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of range");
        array[index] = element;
    }

    // Remove element at specified index
    public void remove(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of range");
        System.arraycopy(array, index + 1, array, index, size - index - 1);
        size--;
    }

    // Get the size of the vector
    public int size() {
        return size;
    }

    // Check if the vector is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Check if the vector contains the specified element
    public boolean contains(int element) {
        for (int i = 0; i < size; i++) {
            if (array[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Clear the vector
    public void clear() {
        Arrays.fill(array, 0);
        size = 0;
    }

    // Ensure capacity of the vector
    private void ensureCapacity() {
        if (size == array.length) {
            int newCapacity = array.length * 2;
            array = Arrays.copyOf(array, newCapacity);
        }
    }

    public static void main(String[] args) {
        // Creating a CustomVector
        CustomVector vector = new CustomVector();

        // Adding elements to the vector
        vector.add(5);
        vector.add(10);
        vector.add(15);
        vector.add(20);

        // Printing the vector
        System.out.println("Vector elements: ");
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.get(i) + " ");
        }
        System.out.println();

        // Accessing elements by index
        int elementAtIndex2 = vector.get(2);
        System.out.println("Element at index 2: " + elementAtIndex2);

        // Updating an element
        vector.set(1, 100);
        System.out.println("Updated vector: ");
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.get(i) + " ");
        }
        System.out.println();

        // Removing an element
        vector.remove(0);
        System.out.println("Vector after removing first element: ");
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.get(i) + " ");
        }
        System.out.println();

        // Checking if an element exists
        boolean contains15 = vector.contains(15);
        System.out.println("Does the vector contain 15? " + contains15);

        // Clearing the vector
        vector.clear();
        System.out.println("Vector after clearing: ");
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.get(i) + " ");
        }
        System.out.println();
    }
}
