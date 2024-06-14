#include <stdio.h>

#define ROWS 3
#define COLS 3
#define DEPTH 3

int main() {
    int arr3D[DEPTH][ROWS][COLS]; // Declaring a 3D array

    // Initializing the 3D array with some values
    for (int i = 0; i < DEPTH; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                arr3D[i][j][k] = i * ROWS * COLS + j * COLS + k + 1;
            }
        }
    }

    // Accessing and printing elements of the 3D array
    printf("3D Array Elements:\n");
    for (int i = 0; i < DEPTH; i++) {
        printf("Depth %d:\n", i + 1);
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                printf("%d ", arr3D[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Performing operations on the 3D array
    // Example: Sum of all elements
    int sum = 0;
    for (int i = 0; i < DEPTH; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                sum += arr3D[i][j][k];
            }
        }
    }
    printf("Sum of all elements: %d\n", sum);

    return 0;
}
