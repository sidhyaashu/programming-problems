package Collection_Framework.List.Stack;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        // Creating a stack
        Stack<Integer> stack = new Stack<>();

        // Pushing elements onto the stack
        System.out.println("Pushing elements onto the stack:");
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);

        // Displaying the stack
        System.out.println("Stack after pushing elements: " + stack);

        // Peeking at the top element of the stack
        System.out.println("Peek at the top element: " + stack.peek());

        // Popping elements from the stack
        System.out.println("Popping elements from the stack:");
        while (!stack.isEmpty()) {
            System.out.println("Popped: " + stack.pop());
        }

        // Checking if the stack is empty after popping
        System.out.println("Is the stack empty now? " + stack.isEmpty());

        // Trying to peek at the top element of an empty stack
        // This will throw EmptyStackException
        // System.out.println(stack.peek());

        // Trying to pop from an empty stack
        // This will throw EmptyStackException
        // System.out.println(stack.pop());
    }
}

