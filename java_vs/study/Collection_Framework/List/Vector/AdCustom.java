package Collection_Framework.List.Vector;

/*
Sorting the vector using Arrays.sort().
Reversing the vector by swapping elements.
Finding the index of the first occurrence of a specified element.
Copying elements to another vector.
 */

 import java.util.Arrays;

public class AdCustom {
    private static final int DEFAULT_CAPACITY = 10;
    private int[] array;
    private int size;

    // Constructor
    public AdCustom() {
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
        AdCustom vector = new AdCustom();

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

        // Sorting the vector
        Arrays.sort(vector.array, 0, vector.size());
        System.out.println("Sorted vector: ");
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.get(i) + " ");
        }
        System.out.println();

        // Reversing the vector
        for (int i = 0; i < vector.size() / 2; i++) {
            int temp = vector.array[i];
            vector.array[i] = vector.array[vector.size() - i - 1];
            vector.array[vector.size() - i - 1] = temp;
        }
        System.out.println("Reversed vector: ");
        for (int i = 0; i < vector.size(); i++) {
            System.out.print(vector.get(i) + " ");
        }
        System.out.println();

        // Find index of element
        int index = -1;
        int elementToFind = 15;
        for (int i = 0; i < vector.size(); i++) {
            if (vector.array[i] == elementToFind) {
                index = i;
                break;
            }
        }
        System.out.println("Index of element " + elementToFind + ": " + index);

        // Copying elements to another vector
        CustomVector copiedVector = new CustomVector();
        for (int i = 0; i < vector.size(); i++) {
            copiedVector.add(vector.get(i));
        }
        System.out.println("Copied vector: ");
        for (int i = 0; i < copiedVector.size(); i++) {
            System.out.print(copiedVector.get(i) + " ");
        }
        System.out.println();
    }
}
