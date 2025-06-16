#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse the list in O(n)
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Save next
        curr->next = prev;   // Reverse current node's pointer
        prev = curr;         // Move prev forward
        curr = next;         // Move current forward
    }
    return prev;  // New head
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Create linked list with 10 nodes
    for (int i = 1; i <= 10; i++) {
        struct Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original List:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
