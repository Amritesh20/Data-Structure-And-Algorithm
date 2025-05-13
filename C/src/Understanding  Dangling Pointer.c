// This program demonstrates the concept of dangling pointers in C.
// It allocates memory for an integer, assigns a value, and then frees the memory.
// After freeing, the pointer is still used, leading to undefined behavior.
// The output will show the value at the pointer after it has been freed, which is not safe.
// The code is written in C and uses the C17 standard.

#include <stdio.h>
#include <stdlib.h>

void createDanglingPointer() {
    // Allocating memory
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    *ptr = 100;  // Assigning value
    
    // Freeing the memory
    free(ptr);

    // At this point, 'ptr' becomes a dangling pointer.
    printf("After free: The value at ptr is: %d\n", *ptr);  // Undefined behavior
}

int main() {
    //Dangling pointer a non-null pointer that points to a memory location that has been freed or deallocated.
    createDanglingPointer();
    return 0;
}