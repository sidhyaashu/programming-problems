/*
push(element): Adds an element to the top of the stack.
pop(): Removes the top element from the stack.
top(): Returns a reference to the top element of the stack without removing it.
empty(): Returns true if the stack is empty, false otherwise.
size(): Returns the number of elements in the stack.
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Create an empty stack
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    // Check if the stack is empty
    if (myStack.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    // Access the top element without removing it (peek)
    cout << "Top element of the stack: " << myStack.top() << endl;

    // Pop elements from the stack
    myStack.pop();
    cout << "Popped one element from the stack." << endl;

    // Access the top element after popping
    cout << "Top element of the stack after pop: " << myStack.top() << endl;

    // Get the size of the stack
    cout << "Size of the stack: " << myStack.size() << endl;

    return 0;
}
