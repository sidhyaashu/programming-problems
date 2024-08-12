package heap;

/*
Constructor: Initializes the heap with a given capacity.
insert(int value): Inserts a new element into the heap. It first checks if the heap is full. If not, it adds the element to the end of the heap array and performs heapifyUp to maintain the heap property.
heapifyUp(int index): Moves the newly inserted element up the heap if necessary to maintain the heap property.
extractMax(): Removes and returns the maximum element from the heap. It first checks if the heap is empty. If not, it removes the root element, replaces it with the last element, and performs heapifyDown to maintain the heap property.
heapifyDown(int index): Moves the root element down the heap if necessary to maintain the heap property.
swap(int index1, int index2): Swaps two elements in the heap.
printHeap(): Prints the elements of the heap.
main(): Demonstrates the usage of the heap by inserting elements, extracting the maximum element, and printing the heap after each operation.
 */
import java.util.Arrays;

public class HeapImplementation {

    private int[] heap;
    private int size;
    private int capacity;

    // Constructor to initialize the heap with a given capacity
    public HeapImplementation(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.heap = new int[capacity];
    }

    // Method to insert a new element into the heap
    public void insert(int value) {
        if (size == capacity) {
            System.out.println("Heap is full. Cannot insert more elements.");
            return;
        }
        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    // Helper method to maintain the heap property by moving the newly inserted element up
    private void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parentIndex]) {
            swap(index, parentIndex);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    // Method to remove and return the maximum element from the heap
    public int extractMax() {
        if (size == 0) {
            System.out.println("Heap is empty. Cannot extract maximum element.");
            return -1; // Assuming -1 represents an invalid value
        }
        int max = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return max;
    }

    // Helper method to maintain the heap property by moving the root element down
    private void heapifyDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largest = index;

        if (leftChildIndex < size && heap[leftChildIndex] > heap[largest]) {
            largest = leftChildIndex;
        }

        if (rightChildIndex < size && heap[rightChildIndex] > heap[largest]) {
            largest = rightChildIndex;
        }

        if (largest != index) {
            swap(index, largest);
            heapifyDown(largest);
        }
    }

    // Method to swap two elements in the heap
    private void swap(int index1, int index2) {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    // Method to print the elements of the heap
    public void printHeap() {
        System.out.println(Arrays.toString(heap));
    }

    public static void main(String[] args) {
        HeapImplementation heap = new HeapImplementation(10);

        heap.insert(5);
        heap.insert(3);
        heap.insert(8);
        heap.insert(1);

        System.out.print("Heap after insertion: ");
        heap.printHeap();

        int max = heap.extractMax();
        System.out.println("Maximum element extracted: " + max);

        System.out.print("Heap after extraction: ");
        heap.printHeap();
    }
}
