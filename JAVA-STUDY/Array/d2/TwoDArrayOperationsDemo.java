package Array.d2;
import java.util.Arrays;

public class TwoDArrayOperationsDemo {

    public static void main(String[] args) {
        // Initializing a 2D array
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        // Accessing Elements
        System.out.println("Accessing Elements:");
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
