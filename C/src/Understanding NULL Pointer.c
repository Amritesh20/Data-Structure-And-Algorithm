// This program demonstrates the use of NULL pointers in C.
// It initializes a pointer to NULL, attempts to allocate memory, checks for successful allocation,
// and safely uses the pointer if allocation is successful.
// The program also includes a good practice of resetting the pointer to NULL after freeing the allocated memory.
// The output will show the value stored at the pointer and confirm successful memory management.
// The code is written in C and uses the C17 standard.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL; // Initialize pointer to NULL

    // Attempt to allocate memory
    ptr = (int *)malloc(sizeof(int));

    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with error
    }

    // Safe to use the pointer
    *ptr = 42;
    printf("Value stored at ptr: %d\n", *ptr);

    // Free allocated memory
    free(ptr);
    ptr = NULL; // Good practice: reset pointer after freeing

    return 0;
}
// This program demonstrates the use of NULL pointers in C.
// It initializes a pointer to NULL, attempts to allocate memory, checks for successful allocation,
// and safely uses the pointer if allocation is successful.
// The program also includes a good practice of resetting the pointer to NULL after freeing the allocated memory.
// The output will show the value stored at the pointer and confirm successful memory management.
// The code is written in C and uses the C17 standard.