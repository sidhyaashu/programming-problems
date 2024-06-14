#include <stdio.h>
#include <stdlib.h>

// Node structure for multi-level linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* child;
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
    newNode->child = NULL;
    return newNode;
}

// Function to append a child list to the parent node
void appendChild(struct Node* parent, struct Node* child) {
    parent->child = child;
}

// Function to print the multi-level linked list
void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->child != NULL) {
            printf("(");
            printList(current->child);
            printf(")");
        }
        current = current->next;
    }
}

int main() {
    // Creating the multi-level linked list
    struct Node* head = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);
    struct Node* node6 = createNode(6);

    appendChild(head, node2);
    appendChild(node2, node3);
    appendChild(node3, node4);
    appendChild(node4, node5);
    appendChild(node3, node6);

    // Printing the multi-level linked list
    printf("Multi-level linked list: ");
    printList(head);
    printf("\n");

    return 0;
}
