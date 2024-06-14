/*
Dynamically allocating memory for the array using new.
Initializing dynamic array elements.
Printing array elements.
Accessing array elements by pointer arithmetic.
Modifying array elements.
Deallocating memory using delete[].
*/

#include <iostream>

using namespace std;

// Function to print array elements
void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int size;

    // Getting array size from user
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocating memory for the array
    int* dynamicArray = new int[size];

    // Initializing dynamic array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> *(dynamicArray + i);
    }

    // Printing array elements
    cout << "Array elements: ";
    printArray(dynamicArray, size);

    // Accessing array elements
    cout << "Element at index 2: " << *(dynamicArray + 2) << endl;

    // Modifying array elements
    *(dynamicArray + 3) = 10;
    cout << "Modified array: ";
    printArray(dynamicArray, size);

    // Deallocating memory
    delete[] dynamicArray;

    return 0;
}
