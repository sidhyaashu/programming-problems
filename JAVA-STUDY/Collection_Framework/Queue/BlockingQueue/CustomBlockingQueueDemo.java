package Collection_Framework.Queue.BlockingQueue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class CustomBlockingQueueDemo {

    public static void main(String[] args) {
        // Creating a BlockingQueue with a capacity of 5
        BlockingQueue<Integer> blockingQueue = new ArrayBlockingQueue<>(5);

        // Adding elements to the BlockingQueue
        try {
            blockingQueue.put(1); // Add element 1
            blockingQueue.put(2); // Add element 2
            blockingQueue.put(3); // Add element 3
            blockingQueue.put(4); // Add element 4
            blockingQueue.put(5); // Add element 5
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Offer: Inserts the specified element into this queue if possible without violating capacity restrictions.
        boolean offerResult = blockingQueue.offer(6);
        System.out.println("Offer Result: " + offerResult); // Output: false (Queue is full)

        // Offer with timeout: Inserts the specified element into this queue if possible, waiting up to 2 seconds for space to become available.
        try {
            boolean offerTimeoutResult = blockingQueue.offer(6, 2, TimeUnit.SECONDS);
            System.out.println("Offer with Timeout Result: " + offerTimeoutResult); // Output: false (Queue is still full after waiting for 2 seconds)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Peek: Retrieves, but does not remove, the head of this queue, or returns null if empty.
        Integer peekValue = blockingQueue.peek();
        System.out.println("Peek Value: " + peekValue); // Output: 1 (Head of the queue)

        // Poll: Retrieves and removes the head of this queue, or returns null if empty.
        Integer pollValue = blockingQueue.poll();
        System.out.println("Poll Value: " + pollValue); // Output: 1 (Head of the queue)

        // Poll with timeout: Retrieves and removes the head of this queue, waiting up to 2 seconds if necessary for an element to become available.
        try {
            Integer pollTimeoutValue = blockingQueue.poll(2, TimeUnit.SECONDS);
            System.out.println("Poll with Timeout Value: " + pollTimeoutValue); // Output: 2 (Head of the queue after waiting for 2 seconds)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Remaining elements in the queue: [3, 4, 5]
        System.out.println("Remaining Elements in the Queue: " + blockingQueue);

        // Additional Functionality:

        // Size: Returns the number of elements in the queue.
        int size = blockingQueue.size();
        System.out.println("Queue Size: " + size); // Output: 3

        // Contains: Checks if the queue contains a specific element.
        boolean contains = blockingQueue.contains(3);
        System.out.println("Queue Contains 3: " + contains); // Output: true
    }
}

