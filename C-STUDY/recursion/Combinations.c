/**
 Combinations refer to the selection of items from a collection, regardless of the order. For example, given a set of elements {1, 2, 3}, the combinations of 2 elements would be {1, 2}, {1, 3}, and {2, 3}.
*/

#include <stdio.h>
#include <stdbool.h>

void generateCombinationsUtil(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int i = 0; i < r; i++)
            printf("%d ", data[i]);
        printf("\n");
        return;
    }
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        generateCombinationsUtil(arr, data, i + 1, end, index + 1, r);
    }
}

void generateCombinations(int arr[], int n, int r) {
    int data[r];
    generateCombinationsUtil(arr, data, 0, n - 1, 0, r);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = 2; // Size of combinations
    generateCombinations(arr, n, r);
    return 0;
}
