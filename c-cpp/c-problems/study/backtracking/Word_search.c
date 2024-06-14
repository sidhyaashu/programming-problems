#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROW 3
#define COL 14

bool searchWord(char grid[ROW][COL], int row, int col, char* word) {
    if (grid[row][col] != word[0])
        return false;

    int len = strlen(word);
    int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dirY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int dir = 0; dir < 8; dir++) {
        int k, rd = row + dirX[dir], cd = col + dirY[dir];

        for (k = 1; k < len; k++) {
            if (rd >= ROW || rd < 0 || cd >= COL || cd < 0)
                break;
            if (grid[rd][cd] != word[k])
                break;
            rd += dirX[dir];
            cd += dirY[dir];
        }

        if (k == len)
            return true;
    }
    return false;
}

void wordSearch(char grid[ROW][COL], char* word) {
    bool found = false;
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (searchWord(grid, row, col, word)) {
                printf("Word found at position (%d,%d)\n", row, col);
                found = true;
            }
        }
    }
    if (!found)
        printf("Word not found in the grid\n");
}

int main() {
    char grid[ROW][COL] = {{'G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S', 'Q'},
                           {'U', 'E', 'I', 'E', 'S', 'O', 'D', 'G', 'E', 'E', 'K', 'S', 'K', 'E'},
                           {'Q', 'T', 'R', 'O', 'C', 'K', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E'}};
    char word[] = "GEEKS";
    wordSearch(grid, word);
    return 0;
}
