package Array;
import java.util.Arrays;

public class ArrayOperationsDemo {

    public static void main(String[] args) {
        // Demonstration of operations on a 1D array
        System.out.println("Operations on 1D Array:");
        int[] arr = {3, 1, 4, 1, 5};

        // Accessing Elements
        System.out.println("\nAccessing Elements:");
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
        System.out.println("\nStream Operations:");
        Arrays.stream(arr2)
                .map(x -> x * 2)
                .forEach(System.out::println);

        // Parallel Operations (Java 8 and above)
        System.out.println("\nParallel Operations:");
        Arrays.stream(arr2)
                .parallel()
                .map(x -> x * 2)
                .forEach(System.out::println);

        // Demonstration of operations on a 2D array
        System.out.println("\nOperations on 2D Array:");
        int[][] matrix = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        // Accessing Elements
        System.out.println("\nAccessing Elements:");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        // Modifying Elements
        matrix[1][1] = 10; // Changing the value of an element

        // Array Length
        System.out.println("\nArray Length:");
        System.out.println("Number of rows: " + matrix.length);
        System.out.println("Number of columns in first row: " + matrix[0].length);

        // Sorting
        // Sorting the first row
        System.out.println("\nSorting:");
        Arrays.sort(matrix[0]);
        for (int num : matrix[0]) {
            System.out.print(num + " ");
        }

        // Searching
        // Searching for element 5 in the matrix
        boolean found = false;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 5) {
                    found = true;
                    break;
                }
            }
        }
        System.out.println("\n\nElement 5 found: " + found);

        // Copying
        // Copying the matrix
        int[][] copiedMatrix = new int[matrix.length][];
        for (int i = 0; i < matrix.length; i++) {
            copiedMatrix[i] = Arrays.copyOf(matrix[i], matrix[i].length);
        }
        System.out.println("\nCopied Matrix:");
        for (int i = 0; i < copiedMatrix.length; i++) {
            for (int j = 0; j < copiedMatrix[i].length; j++) {
                System.out.print(copiedMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}

