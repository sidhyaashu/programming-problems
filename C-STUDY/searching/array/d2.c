#include <stdio.h>

#define ROWS 3
#define COLS 3

void linear_search_2d(int arr[][COLS], int target) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == target) {
                printf("Linear Search Result: [%d][%d]\n", i, j);
                return;
            }
        }
    }
    printf("Element not found\n");
}

void binary_search_2d(int arr[][COLS], int target) {
    int low = 0;
    int high = ROWS * COLS - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / COLS;
        int col = mid % COLS;
        if (arr[row][col] == target) {
            printf("Binary Search Result: [%d][%d]\n", row, col);
            return;
        } else if (arr[row][col] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not found\n");
}

int main() {
    int arr_2d[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int target = 6;
    linear_search_2d(arr_2d, target);
    binary_search_2d(arr_2d, target);
    return 0;
}
