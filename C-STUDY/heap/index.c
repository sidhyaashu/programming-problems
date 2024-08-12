/*
In C programming language, "heap" typically refers to dynamic memory allocation, where memory is allocated and deallocated during program execution. Here, I'll provide an overview of heap concepts and common heap operations along with code examples.

Heap Concepts:
Dynamic Memory Allocation: The process of allocating memory at runtime.
Heap Memory: Memory allocated from the heap, which is managed by the program.
Memory Management Functions: Functions for allocating and deallocating memory dynamically.
Common Heap Operations:



Memory Allocation:

malloc(): Allocates a specified number of bytes of memory.
calloc(): Allocates memory for an array of elements, initializing them to zero.
realloc(): Resizes previously allocated memory block.



Memory Deallocation:

free(): Deallocates previously allocated memory.




*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    // Memory allocation
    int *ptr = (int*)malloc(sizeof(int)); // Allocates memory for one integer
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Memory usage
    *ptr = 10;
    printf("Value stored at ptr: %d\n", *ptr);

    // Memory reallocation
    int *ptr_realloc = (int*)realloc(ptr, 2 * sizeof(int)); // Resizes to hold two integers
    if (ptr_realloc == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Memory usage after reallocation
    ptr = ptr_realloc;
    *(ptr + 1) = 20;
    printf("Value stored at ptr[0]: %d\n", ptr[0]);
    printf("Value stored at ptr[1]: %d\n", ptr[1]);

    // Memory deallocation
    free(ptr);
    
    return 0;
}



/*

Always check if memory allocation (malloc(), calloc(), realloc()) is successful by verifying if the returned pointer is not NULL.
Use free() to deallocate memory after use to prevent memory leaks.
Avoid accessing memory after deallocation (free()) as it leads to undefined behavior.

*/