

#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the solved Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

// Function to check if a given digit can be placed in the given row and column
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if num is not already present in the current row, current column, and current 3x3 subgrid
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
            return false;
    }
    return true;
}

// Function to solve the Sudoku grid using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Check if there is any unassigned cell
    bool found = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    // If no unassigned cell is found, Sudoku is solved
    if (!found) return true;

    // Try placing digits 1 to 9 in the unassigned cell
    for (int num = 1; num <= 9; num++) {
        // Check if it's safe to place num at the current cell
        if (isSafe(grid, row, col, num)) {
            // Place num in the current cell
            grid[row][col] = num;

            // Recur to solve the rest of the grid
            if (solveSudoku(grid)) return true;

            // If placing num doesn't lead to a solution, backtrack and try the next digit
            grid[row][col] = 0; // Undo the assignment
        }
    }

    // If no digit can be placed in the current cell, backtrack
    return false;
}

int main() {
    int grid[N][N] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9} };

    if (solveSudoku(grid) == true)
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}
