#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int binarySearch(struct Node* head, int target) {
    if (head == NULL)
        return 0; // Not found
    
    if (head->data == target)
        return 1; // Found
    
    if (head->data > target)
        return 0; // Not found, as list is sorted
    
    return binarySearch(head->next, target);
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
    
    printf("%d\n", binarySearch(head, 2)); // Output: 1 (True)
    printf("%d\n", binarySearch(head, 5)); // Output: 0 (False)
    
    return 0;
}
