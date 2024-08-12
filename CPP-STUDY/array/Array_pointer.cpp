/*
Initializing a 2D array.
Printing 2D array elements.
Accessing array elements by row and column indices.
Modifying array elements.
Finding array dimensions (number of rows and columns).
Summing array elements.
Finding the maximum element in the array.
Finding the minimum element in the array.

*/

#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Function to print 2D array elements
void printArray(int arr[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initializing a 2D array
    int multiDimArray[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Printing 2D array elements
    cout << "Array elements:" << endl;
    printArray(multiDimArray, ROWS, COLS);

    // Accessing array elements
    cout << "Element at row 1, column 2: " << multiDimArray[1][2] << endl;

    // Modifying array elements
    multiDimArray[2][1] = 10;
    cout << "Modified array:" << endl;
    printArray(multiDimArray, ROWS, COLS);

    // Finding array dimensions
    cout << "Number of rows: " << ROWS << endl;
    cout << "Number of columns: " << COLS << endl;

    // Summing array elements
    int sum = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            sum += multiDimArray[i][j];
        }
    }
    cout << "Sum of array elements: " << sum << endl;

    // Finding maximum element
    int maxElement = multiDimArray[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (multiDimArray[i][j] > maxElement) {
                maxElement = multiDimArray[i][j];
            }
        }
    }
    cout << "Maximum element in array: " << maxElement << endl;

    // Finding minimum element
    int minElement = multiDimArray[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (multiDimArray[i][j] < minElement) {
                minElement = multiDimArray[i][j];
            }
        }
    }
    cout << "Minimum element in array: " << minElement << endl;

    return 0;
}
