/*
In the PriorityQueue class template, a custom comparator is added to allow users to create priority queues with different ordering criteria (e.g., min heap, max heap).
The updatePriority method allows updating the priority of a specific element in the priority queue. It searches for the element and updates its priority accordingly, then adjusts the heap if needed.
The clear method clears all elements from the priority queue.

*/

#include <iostream>
#include <vector>
#include <functional> // for std::greater

template<typename T, typename Compare = std::less<T>>
class PriorityQueue {
private:
    std::vector<T> heap;
    Compare comp; // Custom comparator for priority queue

    // Helper function to maintain heap property after inserting an element
    void heapifyUp(int index) {
        while (index > 0 && comp(heap[parent(index)], heap[index])) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Helper function to maintain heap property after removing an element
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && comp(heap[largest], heap[left]))
            largest = left;

        if (right < heap.size() && comp(heap[largest], heap[right]))
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

    // Method to update the priority of an element
    void updatePriority(const T& oldValue, const T& newValue) {
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == oldValue) {
                heap[i] = newValue;
                if (comp(newValue, oldValue)) {
                    heapifyUp(i);
                } else {
                    heapifyDown(i);
                }
                return;
            }
        }
        throw std::invalid_argument("Element not found in priority queue");
    }

    // Method to clear the priority queue
    void clear() {
        heap.clear();
    }
};

int main() {
    // Creating a custom priority queue of integers with custom comparator (min heap)
    PriorityQueue<int, std::greater<int>> pq;

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

    // Updating the priority of an element
    pq.updatePriority(50, 5);

    // Printing the top element after updating priority
    std::cout << "Top element after updating priority: " << pq.top() << std::endl;

    // Checking if the priority queue is empty
    if (pq.empty()) {
        std::cout << "Priority queue is empty" << std::endl;
    } else {
        std::cout << "Priority queue is not empty" << std::endl;
    }

    // Clearing the priority queue
    pq.clear();
    std::cout << "Size of priority queue after clearing: " << pq.size() << std::endl;

    return 0;
}
