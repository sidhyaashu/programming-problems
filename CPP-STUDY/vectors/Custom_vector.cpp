/*
Constructor and Destructor: Initializes and cleans up memory used by the vector.
Copy Constructor and Assignment Operator: Copies the contents of another vector.
getSize(): Returns the current size of the vector.
getCapacity(): Returns the current capacity of the vector.
empty(): Checks if the vector is empty.
push_back(): Adds an element to the end of the vector.
Operator[]: Accesses elements using the subscript operator.
at(): Accesses an element at the specified index and throws an exception if the index is out of range.
front(): Accesses the first element of the vector.
back(): Accesses the last element of the vector.
pop_back(): Removes the last element from the vector.
erase(): Removes an element at the specified index.
insert(): Inserts an element at the specified index.
resize(): Resizes the vector.
clear(): Removes all elements from the vector.
begin(): Returns an iterator to the beginning of the vector.
end(): Returns an iterator to the end of the vector.
*/

#include <iostream>
#include <stdexcept>

template<typename T>
class CustomVector {
private:
    T* array; // Pointer to dynamically allocated array
    size_t capacity; // Current capacity of the vector
    size_t size; // Current size of the vector

    // Helper function to resize the vector when needed
    void resize(size_t newCapacity) {
        T* newArray = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    // Constructor
    CustomVector() : array(nullptr), capacity(0), size(0) {}

    // Destructor
    ~CustomVector() {
        delete[] array;
    }

    // Copy constructor
    CustomVector(const CustomVector& other) : capacity(other.capacity), size(other.size) {
        array = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }

    // Assignment operator
    CustomVector& operator=(const CustomVector& other) {
        if (this != &other) {
            delete[] array;
            capacity = other.capacity;
            size = other.size;
            array = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    // Method to get the current size of the vector
    size_t getSize() const {
        return size;
    }

    // Method to get the current capacity of the vector
    size_t getCapacity() const {
        return capacity;
    }

    // Method to check if the vector is empty
    bool empty() const {
        return size == 0;
    }

    // Method to add an element to the end of the vector
    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : 2 * capacity);
        }
        array[size++] = value;
    }

    // Operator[] to access elements using subscript operator
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    // Method to access an element at a specific index
    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    // Method to access the first element of the vector
    T& front() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return array[0];
    }

    // Method to access the last element of the vector
    T& back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return array[size - 1];
    }

    // Method to remove the last element from the vector
    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    // Method to erase an element at a specific index
    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
    }

    // Method to insert an element at a specific index
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : 2 * capacity);
        }
        for (size_t i = size; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = value;
        ++size;
    }

    // Method to resize the vector
    void resize(size_t newSize) {
        if (newSize > capacity) {
            resize(newSize * 2);
        } else if (newSize < size) {
            size = newSize;
        }
    }

    // Method to clear all elements from the vector
    void clear() {
        size = 0;
    }

    // Method to get an iterator to the beginning of the vector
    T* begin() {
        return array;
    }

    // Method to get an iterator to the end of the vector
    T* end() {
        return array + size;
    }
};

int main() {
    CustomVector<int> myVector;

    // Adding elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Accessing elements using the at() method
    std::cout << "Element at index 1: " << myVector.at(1) << std::endl;

    // Accessing elements using the subscript operator []
    std::cout << "Element at index 2: " << myVector[2] << std::endl;

    // Accessing the first element
    std::cout << "First element: " << myVector.front() << std::endl;

    // Accessing the last element
    std::cout << "Last element: " << myVector.back() << std::endl;

    // Checking if the vector is empty
    std::cout << "Is the vector empty? " << (myVector.empty() ? "Yes" : "No") << std::endl;

    // Getting the size of the vector
    std::cout << "Size of vector: " << myVector.getSize() << std::endl;

    // Resizing the vector
    myVector.resize(5);

    // Iterating over the vector using iterators
    std::cout << "Vector elements: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Removing elements from the end of the vector
    myVector.pop_back();

    // Erasing an element from the vector
    myVector.erase(1);

    // Inserting an element at a specific position
    myVector.insert(1, 50);

    // Clearing the vector
    myVector.clear();

    return 0;
}
