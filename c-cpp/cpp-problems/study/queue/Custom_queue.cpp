/*
enqueue(element): Adds an element to the rear of the queue by appending it to the end of the vector and updating the rear index.
dequeue(): Removes the front element from the queue by incrementing the front index.
front(): Returns the front element of the queue without removing it by accessing the element at the front index.
isEmpty(): Returns true if the queue is empty, false otherwise by checking if the front index surpasses the rear index.
size(): Returns the number of elements in the queue by calculating the difference between the rear and front indices.
*/

//using a dynamic array (vector)

#include <iostream>
#include <vector>

using namespace std;

class CustomQueue {
private:
    vector<int> elements; // Dynamic array to store elements
    int frontIndex; // Index of the front element
    int rearIndex; // Index of the rear element
public:
    // Constructor
    CustomQueue() {
        frontIndex = -1; // Initialize front index
        rearIndex = -1; // Initialize rear index
    }

    // Method to enqueue an element into the queue
    void enqueue(int element) {
        if (frontIndex == -1) {
            // If queue is empty, set frontIndex to 0
            frontIndex = 0;
        }
        rearIndex++; // Increment rear index
        elements.push_back(element); // Add element to the end of the vector
    }

    // Method to dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            frontIndex++; // Increment front index to remove the front element
        }
    }

    // Method to access the front element of the queue
    int front() {
        if (!isEmpty()) {
            return elements[frontIndex]; // Return the front element
        } else {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Return a default value indicating queue is empty
        }
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return frontIndex > rearIndex; // If front index surpasses rear index, the queue is empty
    }

    // Method to get the size of the queue
    int size() {
        return rearIndex - frontIndex + 1; // Return the number of elements in the queue
    }
};

int main() {
    CustomQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element of the queue: " << myQueue.front() << endl;

    myQueue.dequeue();

    cout << "Front element of the queue after dequeue: " << myQueue.front() << endl;

    cout << "Size of the queue: " << myQueue.size() << endl;

    return 0;
}
