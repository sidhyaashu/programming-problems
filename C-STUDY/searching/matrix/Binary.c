#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void searchInSortedMatrix(int matrix[][4], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        int index = binarySearch(matrix[i], cols, key);
        if (index != -1) {
            printf("Element found at (%d, %d)\n", i, index);
            return;
        }
    }
    printf("Element not found\n");
}

int main() {
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int key = 16;
    searchInSortedMatrix(matrix, 3, 4, key);
    return 0;
}
