// This program demonstrates the use of void pointers in C.
// It defines a function `printValue` that takes a void pointer and a character indicating the type of data.
// The function uses a switch statement to determine the type and prints the value accordingly.
// The `main` function initializes variables of different types and calls `printValue` with their addresses and type indicators.
// This example illustrates how void pointers can be used to create generic functions that can handle different data types.

#include <stdio.h>

void printValue(void* ptr, char type) {
    switch (type) {
        case 'i':
            printf("Integer: %d\n", *(int*)ptr);
            break;
        case 'f':
            printf("Float: %.2f\n", *(float*)ptr);
            break;
        case 'c':
            printf("Character: %c\n", *(char*)ptr);
            break;
        default:
            printf("Unknown type\n");
    }
}

int main() {
    int i = 42;
    float f = 3.14f;
    char c = 'A';

    printValue(&i, 'i');  // Pass integer
    printValue(&f, 'f');  // Pass float
    printValue(&c, 'c');  // Pass char

    return 0;
}