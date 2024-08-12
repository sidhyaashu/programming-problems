#include <stdio.h>

#define DIM1 2
#define DIM2 3
#define DIM3 4

// Define a structure to represent a tensor
typedef struct {
    int data[DIM1][DIM2][DIM3];
} Tensor;

// Function to initialize a tensor
void initializeTensor(Tensor* tensor) {
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            for (int k = 0; k < DIM3; k++) {
                tensor->data[i][j][k] = i + j + k;
            }
        }
    }
}

// Function to print the tensor
void printTensor(Tensor* tensor) {
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            for (int k = 0; k < DIM3; k++) {
                printf("%d ", tensor->data[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    Tensor tensor;
    initializeTensor(&tensor);
    printf("Tensor:\n");
    printTensor(&tensor);
    return 0;
}
