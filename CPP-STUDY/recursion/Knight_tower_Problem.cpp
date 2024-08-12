#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

void printSolution(const vector<vector<int>>& sol) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int x, int y, const vector<vector<int>>& sol) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

bool solveKnightTourUtil(int x, int y, int move, vector<vector<int>>& sol, const vector<int>& xMove, const vector<int>& yMove) {
    if (move == N * N)
        return true;
    for (int k = 0; k < 8; ++k) {
        int nextX = x + xMove[k];
        int nextY = y + yMove[k];
        if (isSafe(nextX, nextY, sol)) {
            sol[nextX][nextY] = move;
            if (solveKnightTourUtil(nextX, nextY, move + 1, sol, xMove, yMove))
                return true;
            else
                sol[nextX][nextY] = -1;
        }
    }
    return false;
}

bool solveKnightTour() {
    vector<vector<int>> sol(N, vector<int>(N, -1));
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};
    sol[0][0] = 0;
    if (!solveKnightTourUtil(0, 0, 1, sol, xMove, yMove)) {
        cout << "Solution does not exist";
        return false;
    } else {
        cout << "Solution exists:" << endl;
        printSolution(sol);
        return true;
    }
}

int main() {
    solveKnightTour();
    return 0;
}
