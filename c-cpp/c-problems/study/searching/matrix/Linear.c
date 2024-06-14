#include <stdio.h>

int search(int matrix[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == key) {
                printf("Element found at (%d, %d)\n", i, j);
                return 1; // Element found
            }
        }
    }
    printf("Element not found\n");
    return 0; // Element not found
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int key = 5;
    search(matrix, 3, 3, key);
    return 0;
}
