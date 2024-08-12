#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations of a string using backtracking
void permute(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
        return;
    }

    for (int i = left; i <= right; i++) {
        swap((str + left), (str + i));
        permute(str, left + 1, right);
        swap((str + left), (str + i)); // backtrack
    }
}

int main() {
    char str[] = "ABC";
    int n = sizeof(str) - 1;
    permute(str, 0, n - 1);
    return 0;
}
