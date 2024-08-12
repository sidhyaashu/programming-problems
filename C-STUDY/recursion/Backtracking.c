/*
Backtracking is a technique used to systematically search for solutions to problems by exploring all possible candidates in a particular space. It involves building solutions step by step and backtracking when a candidate solution is found to be invalid. Common examples include solving puzzles like Sudoku, N-Queens, and generating permutations or combinations.
*/

// Backtracking to generate permutations of a string
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
