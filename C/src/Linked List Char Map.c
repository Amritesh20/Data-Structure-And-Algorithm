#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    char letter;
    struct Node* next;
} Node;

// Convert int to corresponding character in [a-zA-Z]
char intToChar(int value) {
    value = (value - 1) % 52 + 1; // wrap between 1 and 52
    if (value <= 26)
        return 'a' + (value - 1);
    else
        return 'A' + (value - 27);
}

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->letter = intToChar(value);
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("Value: %d, Char: %c\n", head->value, head->letter);
        head = head->next;
    }
}

// Free the list
void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Example usage
int main() {
    Node* head = createNode(2);     // b
    head->next = createNode(28);    // B
    head->next->next = createNode(53); // a again due to wraparound

    printList(head);
    freeList(head);
    return 0;
}
