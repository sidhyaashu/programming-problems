package Collection_Framework.Queue.PriorityQueue;
import java.util.ArrayList;
import java.util.List;

class MyPriorityQueue<T extends Comparable<T>> {
    private List<T> heap;

    // Constructor to initialize an empty priority queue
    public MyPriorityQueue() {
        heap = new ArrayList<>();
    }

    // Method to add an element to the priority queue
    public void offer(T element) {
        heap.add(element);
        bubbleUp(heap.size() - 1);
    }

    // Method to remove and return the head of the priority queue
    public T poll() {
        if (isEmpty())
            return null;

        T removedElement = heap.get(0);
        int lastIndex = heap.size() - 1;
        heap.set(0, heap.get(lastIndex));
        heap.remove(lastIndex);
        bubbleDown(0);
        return removedElement;
    }

    // Method to retrieve but not remove the head of the priority queue
    public T peek() {
        return isEmpty() ? null : heap.get(0);
    }

    // Method to check if the priority queue is empty
    public boolean isEmpty() {
        return heap.isEmpty();
    }

    // Method to return the size of the priority queue
    public int size() {
        return heap.size();
    }

    // Method to perform bubble up operation to maintain heap property
    private void bubbleUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap.get(parentIndex).compareTo(heap.get(index)) <= 0)
                break;
            swap(index, parentIndex);
            index = parentIndex;
        }
    }

    // Method to perform bubble down operation to maintain heap property
    private void bubbleDown(int index) {
        int lastIndex = heap.size() - 1;
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallestChildIndex = index;

            if (leftChildIndex <= lastIndex && heap.get(leftChildIndex).compareTo(heap.get(smallestChildIndex)) < 0)
                smallestChildIndex = leftChildIndex;

            if (rightChildIndex <= lastIndex && heap.get(rightChildIndex).compareTo(heap.get(smallestChildIndex)) < 0)
                smallestChildIndex = rightChildIndex;

            if (smallestChildIndex == index)
                break;

            swap(index, smallestChildIndex);
            index = smallestChildIndex;
        }
    }

    // Method to swap two elements in the priority queue
    private void swap(int i, int j) {
        T temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }
}

public class Main {
    public static void main(String[] args) {
        // Creating a custom priority queue of integers
        MyPriorityQueue<Integer> pq = new MyPriorityQueue<>();

        // Adding elements to the priority queue
        pq.offer(5);
        pq.offer(2);
        pq.offer(8);
        pq.offer(1);
        pq.offer(10);

        // Displaying the elements in the priority queue
        System.out.println("Elements in the priority queue: ");
        while (!pq.isEmpty()) {
            System.out.print(pq.poll() + " ");
        }
    }
}
