/*
std::priority_queue is a container adapter that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.
push(x): Inserts element x into the priority queue.
pop(): Removes the top element from the priority queue.
top(): Returns a reference to the top (highest priority) element in the priority queue.
size(): Returns the number of elements in the priority queue.
empty(): Returns true if the priority queue is empty, otherwise false.

*/
#include <iostream>
#include <queue>

int main() {
    // Creating a priority queue of integers
    std::priority_queue<int> pq;

    // Inserting elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    // Printing the size of the priority queue
    std::cout << "Size of priority queue: " << pq.size() << std::endl;

    // Printing the top element (highest priority element) of the priority queue
    std::cout << "Top element: " << pq.top() << std::endl;

    // Removing the top element from the priority queue
    pq.pop();

    // Printing the new top element after removing the previous one
    std::cout << "Top element after pop: " << pq.top() << std::endl;

    // Checking if the priority queue is empty
    if (pq.empty()) {
        std::cout << "Priority queue is empty" << std::endl;
    } else {
        std::cout << "Priority queue is not empty" << std::endl;
    }

    return 0;
}
