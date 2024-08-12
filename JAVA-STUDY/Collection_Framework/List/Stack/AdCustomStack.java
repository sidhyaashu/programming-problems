/*
clear() method clears all elements from the stack by setting them to null and resetting the size to 0.
search() method searches for a given element in the stack and returns its position/index (1-based index, where 1 is the top element).
copy() method creates a copy of the stack by creating a new stack with the same elements and size.
contains() method checks if the stack contains a specific element.
iterator() method returns an iterator over the stack, allowing easy iteration over its elements.
 */


package Collection_Framework.List.Stack;

import java.util.Arrays;
import java.util.Iterator;

public class AdCustomStack<T> implements Iterable<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private Object[] array;
    private int size;

    // Constructor to initialize the stack
    public AdCustomStack() {
        array = new Object[DEFAULT_CAPACITY];
        size = 0;
    }

    // Method to push an element onto the stack
    public void push(T element) {
        if (size == array.length) {
            // If the array is full, resize it
            resizeArray(array.length * 2);
        }
        array[size++] = element;
    }

    // Method to pop an element from the stack
    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        T poppedElement = (T) array[--size];
        array[size] = null; // Avoid memory leak
        return poppedElement;
    }

    // Method to peek at the top element of the stack
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return (T) array[size - 1];
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Method to get the size of the stack
    public int size() {
        return size;
    }

    // Method to resize the array when needed
    private void resizeArray(int newCapacity) {
        Object[] newArray = new Object[newCapacity];
        System.arraycopy(array, 0, newArray, 0, size);
        array = newArray;
    }

    // Method to clear all elements from the stack
    public void clear() {
        Arrays.fill(array, null);
        size = 0;
    }

    // Method to search for an element and return its position/index
    public int search(T element) {
        for (int i = size - 1; i >= 0; i--) {
            if (array[i].equals(element)) {
                return size - i;
            }
        }
        return -1; // Element not found
    }

    // Method to create a copy of the stack
    public CustomStack<T> copy() {
        CustomStack<T> copyStack = new CustomStack<>();
        copyStack.array = Arrays.copyOf(array, array.length);
        copyStack.size = size;
        return copyStack;
    }

    // Method to check if the stack contains a specific element
    public boolean contains(T element) {
        for (int i = 0; i < size; i++) {
            if (array[i].equals(element)) {
                return true;
            }
        }
        return false;
    }

    // Method to create an iterator over the stack
    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int currentIndex = size - 1;

            @Override
            public boolean hasNext() {
                return currentIndex >= 0;
            }

            @Override
            public T next() {
                return (T) array[currentIndex--];
            }
        };
    }

    public static void main(String[] args) {
        // Creating a custom stack
        CustomStack<Integer> stack = new CustomStack<>();

        // Pushing elements onto the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Displaying the stack
        System.out.println("Stack: " + stack.peek());

        // Popping elements from the stack
        int poppedElement = stack.pop();
        System.out.println("Popped Element: " + poppedElement);
        System.out.println("Stack after popping: " + stack.peek());

        // Checking if the stack is empty
        System.out.println("Is the stack empty? " + stack.isEmpty());

        // Getting the size of the stack
        System.out.println("Size of the stack: " + stack.size());

        // Clearing the stack
        stack.clear();
        System.out.println("Stack after clearing: " + stack.peek());

        // Creating a copy of the stack
        CustomStack<Integer> copyStack = stack.copy();
        System.out.println("Copy of the stack: " + copyStack.peek());

        // Checking if the stack contains an element
        System.out.println("Does the stack contain 20? " + stack.contains(20));

        // Searching for an element in the stack
        System.out.println("Position of 20 in the stack: " + stack.search(20));

        // Iterating over the stack
        System.out.println("Iterating over the stack:");
        for (int element : stack) {
            System.out.println(element);
        }
    }
}
