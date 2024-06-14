package Collection_Framework.Queue.PriorityQueue;

import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        // Creating a priority queue
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Adding elements to the priority queue
        pq.offer(5);  // Insertion using offer() method
        pq.offer(2);
        pq.offer(8);
        pq.offer(1);
        pq.offer(10);

        // Displaying the elements in the priority queue
        System.out.println("Elements in the priority queue: " + pq);

        // Retrieving and removing the head of the priority queue
        int head = pq.poll();  // Returns and removes the smallest element
        System.out.println("Head of the priority queue: " + head);

        // Displaying the updated priority queue after removal
        System.out.println("Priority queue after removal: " + pq);

        // Peeking the head of the priority queue
        int peeked = pq.peek();  // Returns the smallest element without removing it
        System.out.println("Peeked element: " + peeked);

        // Checking if the priority queue contains a specific element
        boolean contains = pq.contains(8);
        System.out.println("Priority queue contains 8: " + contains);

        // Size of the priority queue
        int size = pq.size();
        System.out.println("Size of the priority queue: " + size);

        // Removing a specific element from the priority queue
        boolean removed = pq.remove(2);
        System.out.println("Element 2 removed: " + removed);

        // Displaying the final priority queue
        System.out.println("Final priority queue: " + pq);
    }
}

