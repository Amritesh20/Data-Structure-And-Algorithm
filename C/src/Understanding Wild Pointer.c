// This code demonstrates a wild pointer, which is a pointer that has not been initialized to point to a valid memory location.
// Dereferencing a wild pointer leads to undefined behavior, as it may point to a random memory location.

#include <stdio.h>

int main() {
    int *p;  // Wild pointer: uninitialized
    *p = 42; // Undefined behavior: writing to a random memory location

    printf("Value: %d\n", *p);
    return 0;
}