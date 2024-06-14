import java.util.Arrays;

public class ArrayOperationsDemo {

    public static void main(String[] args) {
        // Initialization
        int[] arr = {3, 1, 4, 1, 5};
        
        // Accessing Elements
        System.out.println("Accessing Elements:");
        for (int i = 0; i < arr.length; i++) {
            System.out.println("Element at index " + i + ": " + arr[i]);
        }
        
        // Modifying Elements
        arr[2] = 9; // Changing the value of the element at index 2
        
        // Array Length
        System.out.println("\nArray Length: " + arr.length);
        
        // Sorting
        System.out.println("\nSorting:");
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr)); // Sorted array
        
        // Searching
        int index = Arrays.binarySearch(arr, 4); // Searching for element 4
        System.out.println("\nIndex of element 4: " + index);
        
        // Copying
        int[] copiedArray = Arrays.copyOf(arr, arr.length); // Copying arr to copiedArray
        System.out.println("\nCopied Array: " + Arrays.toString(copiedArray));
        
        // Concatenation
        int[] anotherArray = {2, 7};
        int[] concatenatedArray = new int[arr.length + anotherArray.length];
        System.arraycopy(arr, 0, concatenatedArray, 0, arr.length); // Copying arr to concatenatedArray
        System.arraycopy(anotherArray, 0, concatenatedArray, arr.length, anotherArray.length); // Copying anotherArray to concatenatedArray
        System.out.println("\nConcatenated Array: " + Arrays.toString(concatenatedArray));
        
        // Range Operations
        System.out.println("\nRange Operations:");
        int[] rangeArray = Arrays.copyOfRange(arr, 1, 4); // Copying a range of elements from arr
        System.out.println(Arrays.toString(rangeArray));
        
        // Conversion
        // Converting array to List (ArrayList)
        // Note: You need to import java.util.List and java.util.ArrayList
        java.util.List<Integer> list = Arrays.asList(Arrays.stream(arr).boxed().toArray(Integer[]::new));
        System.out.println("\nConverted to List: " + list);
        
        // Equality Checking
        int[] arr2 = {3, 1, 4, 1, 5}; // Another array with the same elements
        boolean isEqual = Arrays.equals(arr, arr2);
        System.out.println("\nEquality Checking: " + isEqual);
        
        // Fill Operations
        Arrays.fill(arr, 0); // Filling the entire array with 0
        System.out.println("\nFilled Array: " + Arrays.toString(arr));
        
        // Stream Operations (Java 8 and above)
        // Example: Doubling each element using map operation
        System.out.println("\nStream Operations:");
        Arrays.stream(arr2)
              .map(x -> x * 2)
              .forEach(System.out::println);
              
        // Parallel Operations (Java 8 and above)
        // Example: Doubling each element using parallel stream
        System.out.println("\nParallel Operations:");
        Arrays.stream(arr2)
              .parallel()
              .map(x -> x * 2)
              .forEach(System.out::println);
    }
}
