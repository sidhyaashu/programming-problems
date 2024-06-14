/*
Permutations refer to the arrangement of objects in a specific order. For example, given a set of elements {1, 2, 3}, the permutations would be {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, and {3, 2, 1}.

*/


#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(char *str, int left, int right) {
    if (left == right)
        printf("%s\n", str);
    else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            generatePermutations(str, left + 1, right);
            swap((str + left), (str + i)); // Backtrack
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    generatePermutations(str, 0, n - 1);
    return 0;
}
