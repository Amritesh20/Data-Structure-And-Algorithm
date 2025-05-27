#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning (position 0)
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at any position (0-based index)
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete from any position (0-based index)
void deleteFromPosition(struct Node** head, int position) {
    if (position < 0 || *head == NULL) {
        printf("Invalid position or list is empty\n");
        return;
    }

    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test all operations
int main() {
    struct Node* head = NULL;

    // Insert some elements
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtPosition(&head, 15, 1);
    insertAtBeginning(&head, 5);  // 5 -> 10 -> 15 -> 20 -> 30
    displayList(head);

    // Deletion operations
    deleteFromBeginning(&head);   // Delete 5
    displayList(head);            // 10 -> 15 -> 20 -> 30

    deleteFromEnd(&head);         // Delete 30
    displayList(head);            // 10 -> 15 -> 20

    deleteFromPosition(&head, 2); // Delete 20
    displayList(head);            // 10 -> 15


    return 0;
}
