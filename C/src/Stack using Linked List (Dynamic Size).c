#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Error\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Peek operation
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Check if stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Driver code
int main() {
    struct Node* stack = NULL;

    push(&stack, 100);
    push(&stack, 200);
    push(&stack, 300);

    printf("Top element: %d\n", peek(stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Top element after popping: %d\n", peek(stack));

    return 0;
}
