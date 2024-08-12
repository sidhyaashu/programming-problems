#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int linearSearch(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target)
            return 1; // Found
        current = current->next;
    }
    return 0; // Not found
}

// Example usage
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    second->next = NULL;
    head->next = second;
    
    printf("%d\n", linearSearch(head, 2)); // Output: 1 (True)
    printf("%d\n", linearSearch(head, 5)); // Output: 0 (False)
    
    return 0;
}
