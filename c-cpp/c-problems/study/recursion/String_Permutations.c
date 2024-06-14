/*
Permutations of a string involve generating all possible rearrangements of the characters of the string.

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
