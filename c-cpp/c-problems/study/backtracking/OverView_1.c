/**
Here's a simple example of backtracking implemented in C language. Let's say we want to find all permutations of a given set of numbers.



The swap function is used to swap elements in the array.
The permute function generates permutations of the array recursively. It takes parameters such as the array, the starting index, and the ending index of the array.
In each recursive call, it swaps the current element with every other element in the array and recursively generates permutations for the remaining elements.
When start equals end, it means all elements have been fixed and a permutation is found. It prints the permutation.
After printing the permutation, it backtracks by swapping the elements back to their original positions to explore other possibilities.
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *array, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&array[start], &array[i]);
        permute(array, start + 1, end);
        swap(&array[start], &array[i]); // backtrack
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Permutations:\n");
    permute(array, 0, n - 1);

    return 0;
}
