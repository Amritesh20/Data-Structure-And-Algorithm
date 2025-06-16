#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct node** head, int data){
    struct node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position (0-based index)
void insertAtPosition(struct node** head, int data, int position) {
    if (position <= 0 || *head == NULL) {
        insertAtBeginning(head, data);
        return;
    }

    struct node* temp = *head;
    int i = 0;

    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(head, data);
        return;
    }

    struct node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
void deleteFromBeginning(struct node** head) {
    if (*head == NULL) return;

    struct node* temp = *head;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

// Delete from the end
void deleteFromEnd(struct node** head) {
    if (*head == NULL) return;

    struct node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete from a specific position (0-based index)
void deleteFromPosition(struct node** head, int position) {
    if (*head == NULL || position < 0) return;

    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }

    struct node* temp = *head;
    int i = 0;

    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Update a node's data at a specific position (0-based index)
void updateAtPosition(struct node* head, int position, int newData) {
    if (head == NULL || position < 0) return;

    int i = 0;
    struct node* temp = head;
    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    if (temp != NULL) {
        temp->data = newData;
    } else {
        printf("Position %d not found. Update failed.\n", position);
    }
}

// Delete the entire list
void deleteEntireList(struct node** head){
    struct node* current = *head;
    struct node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

// Display list forward
void displayList(struct node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// MAIN function using all operations
int main() {
    struct node* head = NULL;

    // Insertions
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 1);
    insertAtPosition(&head, 5, 0);
    insertAtPosition(&head, 25, 10); // insert at end if out of bounds
    printf("After Insertions:\n");
    displayList(head);

    // Updates
    updateAtPosition(head, 0, 100);   // update first
    updateAtPosition(head, 2, 200);   // update middle
    updateAtPosition(head, 10, 300);  // invalid update
    printf("After Updates:\n");
    displayList(head);

    // Deletions
    deleteFromBeginning(&head);
    printf("After Deleting from Beginning:\n");
    displayList(head);

    deleteFromEnd(&head);
    printf("After Deleting from End:\n");
    displayList(head);

    deleteFromPosition(&head, 1);
    printf("After Deleting from Position 1:\n");
    displayList(head);

    // Delete entire list
    deleteEntireList(&head);
    printf("After Deleting Entire List:\n");
    displayList(head);

    return 0;
}
