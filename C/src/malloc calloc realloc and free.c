// This code demonstrates the use of malloc, calloc, realloc, and free in C.
// It allocates memory for arrays, initializes them, and then deallocates the memory.
// The program checks for successful memory allocation and handles errors appropriately.
// The output will show the values stored in the arrays and confirm successful memory management.
// The code is written in C and uses the C17 standard.
// The code includes necessary headers and uses standard library functions for memory management.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2;
    int i;

    // malloc: Allocate memory for 5 integers
    arr1 = (int *)malloc(10 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation with malloc failed\n");
        return 1;
    }

    // Initialize and print values
    for (i = 0; i < 10; i++) {
        arr1[i] = i + 1;
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }

    // calloc: Allocate memory for 5 integers (zero-initialized)
    arr2 = (int *)calloc(10, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation with calloc failed\n");
        free(arr1); // free previous allocation
        return 1;
    }

    // Print default values
    printf("\nValues from calloc:\n");
    for (i = 0; i < 10; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // realloc: Resize arr1 to hold 10 integers
    arr1 = (int *)realloc(arr1, 15 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory reallocation with realloc failed\n");
        free(arr2);
        return 1;
    }

    // Initialize new elements and print all values
    for (i = 5; i < 15; i++) {
        arr1[i] = i + 1;
    }

    printf("\nValues after realloc:\n");
    for (i = 0; i < 10; i++) {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }
    // free: Deallocate the memory
    free(arr1);
    free(arr2);

    return 0;
}