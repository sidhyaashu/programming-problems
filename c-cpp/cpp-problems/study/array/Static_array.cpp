/**
Initializing a static array.
Printing array elements.
Accessing array elements by index.
Modifying array elements.
Finding the length of the array.
Summing array elements.
Finding the maximum element in the array.
Finding the minimum element in the array.
*/

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Initializing a static array
    int staticArray[ARRAY_SIZE] = {5, 2, 9, 1, 7};

    // Printing array elements
    cout << "Array elements: ";
    printArray(staticArray, ARRAY_SIZE);

    // Accessing array elements
    cout << "Element at index 2: " << staticArray[2] << endl;

    // Modifying array elements
    staticArray[3] = 10;
    cout << "Modified array: ";
    printArray(staticArray, ARRAY_SIZE);

    // Finding array length
    int length = sizeof(staticArray) / sizeof(staticArray[0]);
    cout << "Length of array: " << length << endl;

    // Summing array elements
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += staticArray[i];
    }
    cout << "Sum of array elements: " << sum << endl;

    // Finding maximum element
    int maxElement = staticArray[0];
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (staticArray[i] > maxElement) {
            maxElement = staticArray[i];
        }
    }
    cout << "Maximum element in array: " << maxElement << endl;

    // Finding minimum element
    int minElement = staticArray[0];
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (staticArray[i] < minElement) {
            minElement = staticArray[i];
        }
    }
    cout << "Minimum element in array: " << minElement << endl;

    return 0;
}
