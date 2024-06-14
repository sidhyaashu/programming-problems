package Collection_Framework.List.Stack;

public class CustomStack<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private Object[] array;
    private int size;

    // Constructor to initialize the stack
    public CustomStack() {
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
    }
}
