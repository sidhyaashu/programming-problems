/*
push_front: Adds an element to the front of the list.
push_back: Adds an element to the end of the list.
pop_front: Removes the element from the front of the list.
pop_back: Removes the element from the end of the list.
clear: Clears all elements from the list.
display: Displays the elements of the list.
empty: Checks if the list is empty.
getSize: Returns the size of the list.
*/

#include <iostream>

template <typename T>
class CustomList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    // Constructor
    CustomList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~CustomList() {
        clear();
    }

    // Method to check if the list is empty
    bool empty() const {
        return size == 0;
    }

    // Method to get the size of the list
    size_t getSize() const {
        return size;
    }

    // Method to add an element at the front of the list
    void push_front(const T& data) {
        Node* newNode = new Node(data);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Method to add an element at the end of the list
    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Method to remove the element from the front of the list
    void pop_front() {
        if (!empty()) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // Method to remove the element from the end of the list
    void pop_back() {
        if (!empty()) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // Method to clear the list
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Method to display the elements of the list
    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    CustomList<int> myList;

    myList.push_back(10);
    myList.push_front(5);
    myList.push_back(15);
    myList.push_front(3);

    std::cout << "Elements in the list: ";
    myList.display();

    myList.pop_front();
    myList.pop_back();

    std::cout << "After popping front and back: ";
    myList.display();

    myList.clear();

    std::cout << "List after clearing: ";
    myList.display();

    return 0;
}
