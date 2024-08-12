/*
push(element): Adds an element to the top of the stack by appending it to the end of the vector.
pop(): Removes the top element from the stack by removing the last element of the vector.
top(): Returns the top element of the stack without removing it by accessing the last element of the vector.
empty(): Returns true if the stack is empty, false otherwise by checking if the vector is empty.
size(): Returns the number of elements in the stack by returning the size of the vector.
*/


//stack using a dynamic array (vector)


#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
private:
    vector<int> elements; // Dynamic array to store elements
public:
    // Method to push an element onto the stack
    void push(int element) {
        elements.push_back(element); // Add element to the end of the vector
    }

    // Method to pop an element from the stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back(); // Remove the last element from the vector
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Method to get the top element of the stack without removing it
    int top() {
        if (!elements.empty()) {
            return elements.back(); // Return the last element of the vector
        } else {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Return a default value indicating stack is empty
        }
    }

    // Method to check if the stack is empty
    bool empty() {
        return elements.empty(); // Return true if vector is empty, false otherwise
    }

    // Method to get the size of the stack
    int size() {
        return elements.size(); // Return the number of elements in the vector
    }
};

int main() {
    CustomStack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element of the stack: " << myStack.top() << endl;

    myStack.pop();

    cout << "Top element of the stack after pop: " << myStack.top() << endl;

    cout << "Size of the stack: " << myStack.size() << endl;

    return 0;
}
