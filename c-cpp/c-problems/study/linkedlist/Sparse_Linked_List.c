#include <stdio.h>
#include <stdlib.h>

// Node structure for the sparse linked list
struct Node {
    int row;
    int col;
    int value;
    struct Node* nextRow;
    struct Node* nextCol;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->nextRow = NULL;
    newNode->nextCol = NULL;
    return newNode;
}

// Function to insert a node into the sparse linked list
void insertNode(struct Node** headRef, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->nextRow != NULL && temp->nextRow->row < row)
            temp = temp->nextRow;
        while (temp->nextCol != NULL && temp->nextCol->col < col)
            temp = temp->nextCol;
        if (temp->row == row && temp->col == col) {
            temp->value = value; // Update existing node
            free(newNode); // Free memory of new node
        } else if (temp->row == row) {
            newNode->nextCol = temp->nextCol;
            temp->nextCol = newNode;
        } else if (temp->col == col) {
            newNode->nextRow = temp->nextRow;
            temp->nextRow = newNode;
        } else {
            newNode->nextRow = temp->nextRow;
            temp->nextRow = newNode;
            newNode = createNode(row, col, value);
            newNode->nextCol = temp->nextCol;
            temp->nextCol = newNode;
        }
    }
}

// Function to delete a node from the sparse linked list
void deleteNode(struct Node** headRef, int row, int col) {
    if (*headRef == NULL) return;
    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    while (temp != NULL && (temp->row != row || temp->col != col)) {
        prev = temp;
        temp = temp->nextRow;
    }
    if (temp == NULL) return; // Node not found
    if (prev != NULL)
        prev->nextRow = temp->nextRow;
    else
        *headRef = temp->nextRow;
    free(temp);
}

// Function to print the sparse linked list
void printList(struct Node* head) {
    struct Node* tempRow = head;
    while (tempRow != NULL) {
        struct Node* tempCol = tempRow;
        while (tempCol != NULL) {
            printf("(%d, %d, %d) ", tempCol->row, tempCol->col, tempCol->value);
            tempCol = tempCol->nextCol;
        }
        printf("\n");
        tempRow = tempRow->nextRow;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the sparse linked list
    insertNode(&head, 0, 0, 1);
    insertNode(&head, 0, 1, 0);
    insertNode(&head, 1, 0, 0);
    insertNode(&head, 1, 1, 2);

    printf("Sparse linked list:\n");
    printList(head);

    // Delete node at row 1, column 1
    deleteNode(&head, 1, 1);
    printf("\nLinked list after deleting node at (1, 1):\n");
    printList(head);

    return 0;
}
