#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    // Allocate memory for 3 nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Initialize data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Connect nodes
    head->prev = NULL;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = NULL;

    // Traverse forward
    printf("Forward traversal:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Traverse backward
    printf("\nBackward traversal:\n");
    temp = third;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
