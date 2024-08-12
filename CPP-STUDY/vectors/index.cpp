/*
push_back(): Adds an element to the end of the vector.
operator[]: Accesses elements using the subscript operator.
at(): Accesses elements using the specified index.
back(): Returns a reference to the last element.
front(): Returns a reference to the first element.
empty(): Checks if the vector is empty.
size(): Returns the number of elements in the vector.
resize(): Resizes the vector to contain the specified number of elements.
begin() and end(): Returns iterators pointing to the first and past-the-end elements of the vector, respectively.
pop_back(): Removes the last element from the vector.
erase(): Removes an element from the vector at the specified position.
insert(): Inserts an element at the specified position.
clear(): Removes all elements from the vector.
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> myVector;

    // Adding elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Accessing elements using the subscript operator []
    cout << "First element: " << myVector[0] << endl;

    // Accessing elements using the at() method
    cout << "Second element: " << myVector.at(1) << endl;

    // Accessing the last element
    cout << "Last element: " << myVector.back() << endl;

    // Accessing the first element
    cout << "First element: " << myVector.front() << endl;

    // Checking if the vector is empty
    cout << "Is the vector empty? " << (myVector.empty() ? "Yes" : "No") << endl;

    // Getting the size of the vector
    cout << "Size of vector: " << myVector.size() << endl;

    // Resizing the vector
    myVector.resize(5);

    // Iterating over the vector using iterators
    cout << "Vector elements: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Removing elements from the end of the vector
    myVector.pop_back();

    // Erasing an element from the vector
    myVector.erase(myVector.begin() + 1);

    // Inserting an element at a specific position
    myVector.insert(myVector.begin() + 2, 50);

    // Clearing the vector
    myVector.clear();

    // Rechecking if the vector is empty
    cout << "Is the vector empty? " << (myVector.empty() ? "Yes" : "No") << endl;

    return 0;
}
