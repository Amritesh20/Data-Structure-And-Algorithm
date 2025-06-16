#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to create doubly linked list of n nodes
struct Node* createList(int n) {
    if (n <= 0) return NULL;

    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i <= n; i++) {
        struct Node* temp = createNode(i);
        current->next = temp;
        temp->prev = current;
        current = temp;
    }

    return head;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the doubly linked list in O(n)
struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is previous due to swap)
        current = current->prev;
    }

    // After loop, temp points to the last node's prev, so adjust
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Main function
int main() {
    struct Node* head = createList(10);

    printf("Original Doubly Linked List:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed Doubly Linked List:\n");
    printList(head);

    return 0;
}
