// enqueue():      Adds an element to the rear of the queue.
// dequeue():      Removes an element from the front of the queue.
// isEmpty():      Checks if the queue is empty.
// isFull():       Checks if the queue is full.
// peek():         Returns the element at the front of the queue without removing it.


/*
A queue is a linear data structure in which elements are inserted from one end (rear) and removed from the other end (front). It follows the FIFO (First In First Out) principle, meaning the element that is inserted first will be removed first.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(struct Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Check if the queue is full
bool isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Add an element to the rear of the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

// Remove an element from the front of the queue
int dequeue(struct Queue *q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        value = q->items[q->front];
        q->front = q->rear = -1;
    } else {
        value = q->items[q->front];
        q->front++;
    }
    return value;
}

// Return the element at the front of the queue
int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", peek(&q));

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Front element: %d\n", peek(&q));

    return 0;
}
