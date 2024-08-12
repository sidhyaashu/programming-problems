#include <stdio.h>
#include <stdlib.h>

// Node structure for sorted linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct Node* result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeLists(list1, list2->next);
    }
    return result;
}

// Function to sort the linked list using merge sort algorithm
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* firstHalf;
    struct Node* secondHalf;
    if (head == NULL || head->next == NULL) return; // Base case: empty list or single node
    // Split the list into two halves
    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    firstHalf = head;
    secondHalf = slow->next;
    slow->next = NULL;
    // Recursively sort the two halves
    mergeSort(&firstHalf);
    mergeSort(&secondHalf);
    // Merge the sorted halves
    *headRef = mergeLists(firstHalf, secondHalf);
}

// Function to remove duplicates from the sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Function to insert a node at the end of the sorted linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Sample code
int main() {
    struct Node* head = NULL;

    // Insert elements into the sorted linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 50);

    printf("Sorted linked list before sorting and removing duplicates: ");
    printList(head);

    // Sort the linked list using merge sort
    mergeSort(&head);
    printf("Sorted linked list after sorting: ");
    printList(head);

    // Remove duplicates from the sorted linked list
    removeDuplicates(head);
    printf("Sorted linked list after removing duplicates: ");
    printList(head);

    return 0;
}
