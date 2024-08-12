#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *headRef;
    if (*headRef != NULL)
        (*headRef)->prev = newNode;
    *headRef = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = data;
    newNode->next = NULL;
    if (*headRef == NULL) {
        newNode->prev = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

// Function to delete a node with given data
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *headRef = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// Function to traverse the list forward
void forwardTraversal(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to traverse the list backward
void backwardTraversal(struct Node* node) {
    while (node->next != NULL)
        node = node->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
}

// #() Function to reverse the doubly linked list
void reverseList(struct Node** headRef) {
    struct Node* temp = NULL;
    struct Node* current = *headRef;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *headRef = temp->prev;
    }
}

// #() Function to find intersection point of two doubly linked lists
struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    int len1 = 0, len2 = 0;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;
    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) list1 = list1->next;
    } else {
        while (diff--) list2 = list2->next;
    }
    while (list1 && list2) {
        if (list1 == list2) return list1;
        list1 = list1->next;
        list2 = list2->next;
    }
    return NULL; // No intersection
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);

    printf("Forward traversal: ");
    forwardTraversal(head);
    printf("\n");

    printf("Backward traversal: ");
    backwardTraversal(head);
    printf("\n");

    deleteNode(&head, 20);
    printf("Linked list after deleting node with value 20: ");
    forwardTraversal(head);
    printf("\n");

    return 0;
}
