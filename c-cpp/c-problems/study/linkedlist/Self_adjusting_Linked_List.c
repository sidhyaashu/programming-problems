#include <stdio.h>
#include <stdlib.h>

// Node structure for self-adjusting linked list
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

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to search for a node with given data and move it to the front
void moveToFront(struct Node** headRef, int key) {
    struct Node *prev = NULL, *current = *headRef;
    // Traverse the list to find the key
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return; // Key not found
    if (prev != NULL) {
        prev->next = current->next; // Remove the node from its current position
        current->next = *headRef; // Move the node to the front
        *headRef = current; // Update head
    }
}

// Function to print the self-adjusting linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the self-adjusting linked list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);

    printf("Initial list: ");
    printList(head);

    // Move node with value 30 to the front
    moveToFront(&head, 30);
    printf("List after moving node with value 30 to the front: ");
    printList(head);

    return 0;
}
