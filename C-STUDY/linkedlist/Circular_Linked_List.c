#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
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
    if (*headRef == NULL) {
        newNode->next = newNode; // Point to itself if list is empty
    } else {
        newNode->next = (*headRef)->next; // Point new node to current first node
        (*headRef)->next = newNode; // Point head to new node
    }
    *headRef = newNode; // Update head to the new node
}

// Function to insert a node at the end
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        newNode->next = newNode; // Point to itself if list is empty
        *headRef = newNode; // Update head to the new node
    } else {
        newNode->next = (*headRef)->next; // Point new node to current first node
        (*headRef)->next = newNode; // Point last node to new node
        *headRef = newNode; // Update head to the new node
    }
}

// Function to delete the first occurrence of a node with given data
void deleteNode(struct Node** headRef, int key) {
    if (*headRef == NULL) return;
    struct Node* current = (*headRef)->next;
    struct Node* prev = *headRef;
    // Traverse the list until the end or until the key is found
    while (current != *headRef && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == *headRef && current->data != key) return; // Key not found
    prev->next = current->next; // Remove the node from the list
    if (current == *headRef) // Update head if the deleted node was the head
        *headRef = prev;
    free(current); // Free memory allocated for the deleted node
}

// Function to print the circular linked list starting from a given node
void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head->next;
    printf("%d ", head->data); // Print data of the head node
    // Traverse the list and print data until we reach the head again
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


// #() Function to split circular linked list into two halves
void splitList(struct Node* head, struct Node** head1Ref, struct Node** head2Ref) {
    struct Node* slow = head;
    struct Node* fast = head;
    if (head == NULL) return;
    // Move fast pointer two steps and slow pointer one step
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // If even number of elements, move fast pointer once more
    if (fast->next->next == head) fast = fast->next;
    // Split the list into two at the middle
    *head1Ref = head;
    *head2Ref = (slow->next);
    slow->next = *head1Ref;
    fast->next = *head2Ref;
}

// #() Function to solve Josephus problem using circular linked list
int josephus(struct Node* head, int m) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        printf("%d has been eliminated.\n", current->data);
        free(current);
        current = prev->next;
    }
    int survivor = current->data;
    free(current);
    return survivor;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the circular linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    printf("Circular linked list: ");
    printList(head);

    // Delete node with value 20
    deleteNode(&head, 20);
    printf("Linked list after deleting node with value 20: ");
    printList(head);

    return 0;
}
