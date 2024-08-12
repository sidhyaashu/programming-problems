package Collection_Framework.List.ArrayList;

public class CustomArrayList<T> {
    private Object[] elements;
    private int size;
    private static final int DEFAULT_CAPACITY = 10;

    public CustomArrayList() {
        this.elements = new Object[DEFAULT_CAPACITY];
        this.size = 0;
    }

    // Method to add an element to the list
    public void add(T element) {
        if (size == elements.length) {
            increaseCapacity();
        }
        elements[size++] = element;
    }

    // Method to get an element at a specific index
    @SuppressWarnings("unchecked")
    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return (T) elements[index];
    }

    // Method to remove an element at a specific index
    public void remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        System.arraycopy(elements, index + 1, elements, index, size - index - 1);
        elements[--size] = null;
    }

    // Method to check if an element exists in the list
    public boolean contains(T element) {
        for (Object obj : elements) {
            if (element.equals(obj)) {
                return true;
            }
        }
        return false;
    }

    // Method to get the size of the list
    public int size() {
        return size;
    }

    // Method to clear the list
    public void clear() {
        for (int i = 0; i < size; i++) {
            elements[i] = null;
        }
        size = 0;
    }

    // Method to increase the capacity of the list
    private void increaseCapacity() {
        int newCapacity = elements.length * 2;
        Object[] newArray = new Object[newCapacity];
        System.arraycopy(elements, 0, newArray, 0, size);
        elements = newArray;
    }

    public static void main(String[] args) {
        // Creating a CustomArrayList of Strings
        CustomArrayList<String> customList = new CustomArrayList<>();

        // Adding elements to the list
        customList.add("Apple");
        customList.add("Banana");
        customList.add("Orange");

        // Displaying the list
        System.out.println("CustomArrayList: " + customList);

        // Accessing elements by index
        String firstElement = customList.get(0);
        System.out.println("First element: " + firstElement);

        // Removing an element by index
        customList.remove(1);
        System.out.println("CustomArrayList after removing an element: " + customList);

        // Checking if an element exists
        boolean containsBanana = customList.contains("Banana");
        System.out.println("CustomArrayList contains 'Banana': " + containsBanana);

        // Getting the size of the list
        int size = customList.size();
        System.out.println("Size of CustomArrayList: " + size);

        // Clearing the list
        customList.clear();
        System.out.println("CustomArrayList after clearing: " + customList);
    }
}

