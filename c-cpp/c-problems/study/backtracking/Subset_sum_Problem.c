#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

// Function to find all subsets with given sum using backtracking
void subsetSum(int arr[], int n, int sum, int subset[], int subsetSize, int idx, int targetSum) {
    if (sum == targetSum) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    if (idx == n || sum > targetSum)
        return;

    // Include current element in the subset
    subset[subsetSize] = arr[idx];
    subsetSum(arr, n, sum + arr[idx], subset, subsetSize + 1, idx + 1, targetSum);

    // Exclude current element from the subset and move to the next one
    subsetSum(arr, n, sum, subset, subsetSize, idx + 1, targetSum);
}

int main() {
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int n = ARRAY_SIZE(arr);
    int subset[n];
    int targetSum = 35;

    printf("Subsets with sum %d:\n", targetSum);
    subsetSum(arr, n, 0, subset, 0, 0, targetSum);

    return 0;
}
