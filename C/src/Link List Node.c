#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link the nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Print the linked list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
