package matrix;

/*
initializeMatrix(): This method initializes a matrix with random integer values. It takes the number of rows and columns as parameters and returns the initialized matrix.
displayMatrix(): This method displays the contents of a matrix. It takes a matrix as input and prints each row on a separate line.
addMatrices(): This method adds two matrices element-wise. It takes two matrices as input and returns the resulting matrix after addition.
multiplyMatrices(): This method multiplies two matrices. It takes two matrices as input and returns the resulting matrix after multiplication.
In the main() method, two matrices are initialized using initializeMatrix(), displayed using displayMatrix(), added using addMatrices(), and multiplied using multiplyMatrices(). Finally, the results are displayed.
 */
import java.util.Arrays;

public class MatrixOperations {
    
    // Method to initialize a matrix with random values
    public static int[][] initializeMatrix(int rows, int cols) {
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = (int) (Math.random() * 10); // Random value between 0 and 9
            }
        }
        return matrix;
    }
    
    // Method to display a matrix
    public static void displayMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }
    }
    
    // Method to add two matrices
    public static int[][] addMatrices(int[][] matrix1, int[][] matrix2) {
        int rows = matrix1.length;
        int cols = matrix1[0].length;
        int[][] result = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return result;
    }
    
    // Method to multiply two matrices
    public static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2) {
        int rows1 = matrix1.length;
        int cols1 = matrix1[0].length;
        int cols2 = matrix2[0].length;
        int[][] result = new int[rows1][cols2];
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        int[][] matrix1 = initializeMatrix(2, 3);
        int[][] matrix2 = initializeMatrix(2, 3);
        
        System.out.println("Matrix 1:");
        displayMatrix(matrix1);
        
        System.out.println("\nMatrix 2:");
        displayMatrix(matrix2);
        
        System.out.println("\nAddition Result:");
        int[][] additionResult = addMatrices(matrix1, matrix2);
        displayMatrix(additionResult);
        
        System.out.println("\nMultiplication Result:");
        int[][] multiplicationResult = multiplyMatrices(matrix1, matrix2);
        displayMatrix(multiplicationResult);
    }
}
