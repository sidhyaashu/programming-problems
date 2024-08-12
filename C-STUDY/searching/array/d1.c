#include <stdio.h>

int linear_search_1d(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

int binary_search_1d(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;  // Return the index if found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Return -1 if not found
}

int main() {
    int arr_1d[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr_1d) / sizeof(arr_1d[0]);
    int target = 7;
    printf("Linear Search Result: %d\n", linear_search_1d(arr_1d, size, target));
    printf("Binary Search Result: %d\n", binary_search_1d(arr_1d, size, target));
    return 0;
}
