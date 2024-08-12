//      Push:            Adding an element to the top of the stack.
//      Pop:             Removing the top element from the stack.
//      Peek (or Top):   Viewing the top element without removing it.
//      isEmpty:         Checking if the stack is empty.

/**
 A stack is a linear data structure that follows the LIFO principle, meaning the last element added to the stack is the first one to be removed.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *stack)
{
    stack->top = -1; // Initialize top as -1 to dedicate an empty stack
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto stack
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1; // Return a special value to indicate underflow
    }
    return stack->data[stack->top--];
}

// Function to peek the top element of the stack
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Function to insert a value at a particular position in the stack
void insertAtPosition(Stack *stack, int position, int value)
{
    if (isFull(stack) || position < 0 || position > stack->top + 1)
    {
        printf("Invalid position or stack overflow\n");
        return;
    }

    for (int i = stack->top + 1; i > position; i--)
    {
        stack->data[i] = stack->data[i - 1];
    }

    stack->data[position] = value;
    stack->top++;
}

// Function to delet a value from a particular position in the stack
int deletFromPostion(Stack *stack, int position)
{
    if (isEmpty(stack) || position < 0 || position > stack->top)
    {
        printf("Invalid position or stack underflow\n");
        return -1;
    }

    int deletValue = stack->data[position];

    for (int i = position; i < stack->top; i++)
    {
        stack->data[i] = stack->data[i + i];
    }

    stack->top--;
    return deletValue;
}

int main()
{
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 11);
    push(&stack, 12);
    push(&stack, 13);
    push(&stack, 14);
    push(&stack, 15);

    printf("\n-----------------------------\n");
    printf("Initial stack: \n");
    for (int i = 0; i <= stack.top; i++)
    {
        printf("%d ", stack.data[i]);
    }
    printf("\n-----------------------------\n");

    printf("\n---------------------------\n");
    printf("Top element of the stack: %d\n", peek(&stack));
    printf("\n-----------------------------\n");

    printf("Popping element from the stack: \n");
    while (!isEmpty(&stack))
    {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}