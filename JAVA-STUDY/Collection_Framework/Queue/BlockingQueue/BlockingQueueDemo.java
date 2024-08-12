/*
BlockingQueue is an interface representing a queue that supports operations that wait for the queue to become non-empty when retrieving an element and wait for space to become available in the queue when storing an element.
ArrayBlockingQueue is a concrete implementation of the BlockingQueue interface. It uses an array to store elements and has a fixed capacity.
put(E e): Inserts the specified element into this queue, waiting if necessary for space to become available.
offer(E e): Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions.
offer(E e, long timeout, TimeUnit unit): Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions, waiting up to the specified wait time if necessary for space to become available.
peek(): Retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
poll(): Retrieves and removes the head of this queue, or returns null if this queue is empty.
poll(long timeout, TimeUnit unit): Retrieves and removes the head of this queue, waiting up to the specified wait time if necessary for an element to become available.
 */

package Collection_Framework.Queue.BlockingQueue;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class BlockingQueueDemo {
    public static void main(String[] args) {
        // Creating a BlockingQueue of capacity 5
        BlockingQueue<Integer> blockingQueue = new ArrayBlockingQueue<>(5);

        // Adding elements to the BlockingQueue
        try {
            blockingQueue.put(1);
            blockingQueue.put(2);
            blockingQueue.put(3);
            blockingQueue.put(4);
            blockingQueue.put(5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Offer: Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions.
        boolean offerResult = blockingQueue.offer(6);
        System.out.println("Offer Result: " + offerResult); // Output: false (Queue is full)

        // Offer with timeout: Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions, waiting up to the specified wait time if necessary for space to become available.
        try {
            boolean offerTimeoutResult = blockingQueue.offer(6, 2, TimeUnit.SECONDS);
            System.out.println("Offer with Timeout Result: " + offerTimeoutResult); // Output: false (Queue is still full after waiting for 2 seconds)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Peek: Retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
        Integer peekValue = blockingQueue.peek();
        System.out.println("Peek Value: " + peekValue); // Output: 1 (Head of the queue)

        // Poll: Retrieves and removes the head of this queue, or returns null if this queue is empty.
        Integer pollValue = blockingQueue.poll();
        System.out.println("Poll Value: " + pollValue); // Output: 1 (Head of the queue)

        // Poll with timeout: Retrieves and removes the head of this queue, waiting up to the specified wait time if necessary for an element to become available.
        try {
            Integer pollTimeoutValue = blockingQueue.poll(2, TimeUnit.SECONDS);
            System.out.println("Poll with Timeout Value: " + pollTimeoutValue); // Output: 2 (Head of the queue after waiting for 2 seconds)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Remaining elements in the queue: [3, 4, 5]
        System.out.println("Remaining Elements in the Queue: " + blockingQueue);
    }
}

