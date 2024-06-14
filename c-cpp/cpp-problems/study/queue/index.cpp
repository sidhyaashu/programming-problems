/*
push(element): Adds an element to the back of the queue.
pop(): Removes the front element from the queue.
front(): Returns a reference to the front element of the queue without removing it.
empty(): Returns true if the queue is empty, false otherwise.
size(): Returns the number of elements in the queue.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create an empty queue
    queue<int> myQueue;

    // Enqueue elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    // Check if the queue is empty
    if (myQueue.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    // Access the front element without removing it
    cout << "Front element of the queue: " << myQueue.front() << endl;

    // Dequeue elements from the queue
    myQueue.pop();
    cout << "Dequeued one element from the queue." << endl;

    // Access the front element after dequeue
    cout << "Front element of the queue after dequeue: " << myQueue.front() << endl;

    // Get the size of the queue
    cout << "Size of the queue: " << myQueue.size() << endl;

    return 0;
}
