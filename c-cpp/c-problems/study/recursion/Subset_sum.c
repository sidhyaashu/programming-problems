/*
Subset sum problem involves finding whether there is a subset of a given set whose sum equals a given target sum.
*/

#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isSubsetSum(arr, n, sum))
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");
    return 0;
}
