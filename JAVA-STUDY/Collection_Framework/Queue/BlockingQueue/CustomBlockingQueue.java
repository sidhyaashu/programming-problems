package Collection_Framework.Queue.BlockingQueue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;


public class CustomBlockingQueue {

    public static void main(String[] args) {
        BlockingQueue<Integer> blockingQueue = new ArrayBlockingQueue<>(10);

        // Adding elements to the BlockingQueue
        try {
            blockingQueue.put(5);
            blockingQueue.put(3);
            blockingQueue.put(7);
            blockingQueue.put(1);
            blockingQueue.put(9);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Additional Functionality

        // Custom sorting methods
        sortQueue(blockingQueue);
        System.out.println("Sorted Queue: " + blockingQueue);

        // Custom searching methods
        int elementToSearch = 7;
        boolean isFound = searchElement(blockingQueue, elementToSearch);
        System.out.println("Element " + elementToSearch + " found: " + isFound);

        // Adding more elements to the BlockingQueue
        try {
            blockingQueue.put(2);
            blockingQueue.put(8);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Sorting again after adding more elements
        sortQueue(blockingQueue);
        System.out.println("Sorted Queue after adding more elements: " + blockingQueue);
    }

    // Custom method to sort the BlockingQueue
    private static void sortQueue(BlockingQueue<Integer> queue) {
        Object[] arr = queue.toArray();
        int[] intArr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            intArr[i] = (int) arr[i];
        }
        quickSort(intArr, 0, intArr.length - 1);
        queue.clear();
        for (int num : intArr) {
            queue.offer(num);
        }
    }

    private static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    // Custom method to search for an element in the BlockingQueue
    private static boolean searchElement(BlockingQueue<Integer> queue, int element) {
        return queue.contains(element);
    }
}

