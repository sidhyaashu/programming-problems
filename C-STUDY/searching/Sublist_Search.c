#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the end of a linked list
void insert(Node** headRef, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a sublist within a linked list
int sublistSearch(Node* first, Node* second) {
    if (first == NULL && second == NULL)
        return 1; // Return 1 if second list is NULL
    if (first == NULL || (first != NULL && second == NULL))
        return 0; // Return 0 if first list is NULL or second list is not NULL
    Node* ptr1 = first;
    Node* ptr2 = second;
    while (second != NULL) {
        ptr2 = second;
        while (ptr1 != NULL) {
            if (ptr2 == NULL)
                return 0;
            else if (ptr1->data == ptr2->data) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } else
                break;
        }
        if (ptr1 == NULL)
            return 1; // Return 1 if sublist is found
        ptr1 = first;
        second = second->next;
    }
    return 0; // Return 0 if sublist is not found
}

// Function to display the linked list
void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Creating the main linked list
    Node* firstList = NULL;
    insert(&firstList, 1);
    insert(&firstList, 2);
    insert(&firstList, 3);
    insert(&firstList, 4);
    insert(&firstList, 5);
    insert(&firstList, 6);

    // Creating the sublist
    Node* secondList = NULL;
    insert(&secondList, 2);
    insert(&secondList, 3);
    insert(&secondList, 4);

    // Displaying the main linked list and sublist
    printf("First list: ");
    display(firstList);
    printf("Second list: ");
    display(secondList);

    // Searching for the sublist within the main list
    if (sublistSearch(firstList, secondList))
        printf("Second list is a sublist of the first list.\n");
    else
        printf("Second list is not a sublist of the first list.\n");

    return 0;
}
