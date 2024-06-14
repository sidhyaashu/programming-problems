#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void BFS(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    free(queue);
}
