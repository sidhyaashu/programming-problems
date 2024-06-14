/*
Binary search on a linked list is generally not practical because it requires random access to elements, which is not efficiently supported by linked lists. However, if your linked list is sorted and you still want to implement binary search, you can convert the linked list into an array and then apply binary search. Below is a C code example:

*/


#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to convert the linked list into an array
int* convertLinkedListToArray(struct Node* head, int* size) {
    // Count the number of elements in the linked list
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Allocate memory for the array
    int* arr = (int*)malloc(count * sizeof(int));
    if (arr == NULL) {
        *size = 0;
        return NULL;
    }
    
    // Copy elements from the linked list to the array
    temp = head;
    int index = 0;
    while (temp != NULL) {
        arr[index++] = temp->data;
        temp = temp->next;
    }
    
    // Update size
    *size = count;
    
    return arr;
}

// Function to perform binary search on the array
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return 1; // Found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0; // Not found
}

// Example usage
int main() {
    // Create a sorted linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;
    
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 4;
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    
    // Convert the linked list into an array
    int size;
    int* arr = convertLinkedListToArray(head, &size);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Perform binary search on the array
    int target = 3;
    int result = binarySearch(arr, size, target);
    if (result)
        printf("Element %d found.\n", target);
    else
        printf("Element %d not found.\n", target);
    
    // Free dynamically allocated memory
    free(arr);
    
    return 0;
}
