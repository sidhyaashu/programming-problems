#include <stdio.h>
#include <stdlib.h>

// Node structure for the sorted linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the sorted linked list
void insertSorted(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL || (*headRef)->data >= data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next != NULL && current->next->data < data)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete the first occurrence of a node with given data
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the sorted linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the sorted linked list
    insertSorted(&head, 10);
    insertSorted(&head, 20);
    insertSorted(&head, 5);
    insertSorted(&head, 15);

    printf("Sorted linked list: ");
    printList(head);

    // Delete node with value 20
    deleteNode(&head, 20);
    printf("Linked list after deleting node with value 20: ");
    printList(head);

    return 0;
}
