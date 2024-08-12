/*
Creating a list: Using the std::list template class.
Inserting elements: Using push_back, push_front, and insert.
Accessing elements: Using front() and back() functions.
Iterating through the list: Using iterators.
Removing elements: Using pop_front(), pop_back(), and erase() functions.
Checking if the list is empty: Using empty() function.
Getting the size of the list: Using size() function.
Clearing the list: Using clear() function.
*/

#include <iostream>
#include <list>

int main() {
    // Creating a list
    std::list<int> myList;

    // Inserting elements into the list
    myList.push_back(10);   // Adds element at the end
    myList.push_front(5);   // Adds element at the beginning
    myList.insert(++myList.begin(), 7); // Adds element at the second position

    // Accessing elements
    std::cout << "First Element: " << myList.front() << std::endl;
    std::cout << "Last Element: " << myList.back() << std::endl;

    // Iterating through the list
    std::cout << "Elements in the list: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Removing elements
    myList.pop_front();     // Removes the first element
    myList.pop_back();      // Removes the last element
    myList.erase(++myList.begin()); // Removes the element at the second position

    // Checking if the list is empty
    if (myList.empty()) {
        std::cout << "List is empty." << std::endl;
    } else {
        std::cout << "List is not empty." << std::endl;
    }

    // Getting the size of the list
    std::cout << "Size of the list: " << myList.size() << std::endl;

    // Clearing the list
    myList.clear();

    return 0;
}
