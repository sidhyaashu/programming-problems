#include <stdio.h>
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        sol[x][y] = 0; // Backtrack
        return false;
    }

    return false;
}

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

void solveMaze(int maze[N][N]) {
    int sol[N][N] = { {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0} };

    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printf("Solution found:\n");
    printSolution(sol);
}

int main() {
    int maze[N][N] = { {1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {0, 1, 0, 0},
                       {1, 1, 1, 1} };
    solveMaze(maze);
    return 0;
}
