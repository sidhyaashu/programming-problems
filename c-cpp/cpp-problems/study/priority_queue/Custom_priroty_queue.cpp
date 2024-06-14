/*
The PriorityQueue class template implements a priority queue using a binary heap data structure.
The push method inserts an element into the priority queue and maintains the heap property by calling heapifyUp.
The pop method removes and returns the top element from the priority queue and maintains the heap property by calling heapifyDown.
The top method returns the top element from the priority queue.
The empty method checks if the priority queue is empty.
The size method returns the number of elements in the priority queue.
In the main function, we demonstrate the usage of these methods by creating a PriorityQueue of integers, pushing elements into it, popping elements, accessing the top element, and checking if it's empty.
*/

#include <iostream>
#include <vector>

template<typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    // Helper function to maintain heap property after inserting an element
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Helper function to maintain heap property after removing an element
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Helper function to get the index of the parent node
    int parent(int index) {
        return (index - 1) / 2;
    }

    // Helper function to get the index of the left child node
    int leftChild(int index) {
        return 2 * index + 1;
    }

    // Helper function to get the index of the right child node
    int rightChild(int index) {
        return 2 * index + 2;
    }

public:
    // Method to insert an element into the priority queue
    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Method to remove and return the top element from the priority queue
    T pop() {
        if (heap.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }

        T top = heap.front();
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        heapifyDown(0);

        return top;
    }

    // Method to return the top element from the priority queue
    T top() const {
        if (heap.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        return heap.front();
    }

    // Method to check if the priority queue is empty
    bool empty() const {
        return heap.empty();
    }

    // Method to return the number of elements in the priority queue
    size_t size() const {
        return heap.size();
    }
};

int main() {
    // Creating a custom priority queue of integers
    PriorityQueue<int> pq;

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
