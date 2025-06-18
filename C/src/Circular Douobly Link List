#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* tail = NULL; // tail->next is head

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (tail == NULL) {
        newNode->next = newNode->prev = newNode;
        tail = newNode;
    } else {
        struct Node* head = tail->next;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
    }
}

// Insert at end
void insertAtEnd(int data) {
    insertAtBeginning(data);
    tail = tail->next; // Move tail to new node
}

// Insert at a given position (0-based)
void insertAtPosition(int data, int pos) {
    if (tail == NULL && pos != 0) {
        printf("Position out of bounds (list is empty).\n");
        return;
    }

    if (pos == 0) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = tail->next;
    int count = 0;

    while (count < pos - 1 && temp != tail) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    if (temp == tail) {
        tail = newNode;
    }
}

// Delete from beginning
void deleteFromBeginning() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* head = tail->next;

    if (tail == head) {
        free(tail);
        tail = NULL;
    } else {
        struct Node* newHead = head->next;
        newHead->prev = tail;
        tail->next = newHead;
        free(head);
    }
}

// Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* head = tail->next;

    if (tail == head) {
        free(tail);
        tail = NULL;
    } else {
        struct Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        free(tail);
        tail = newTail;
    }
}

// Delete from a given position (0-based)
void deleteFromPosition(int pos) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* head = tail->next;

    if (pos == 0) {
        deleteFromBeginning();
        return;
    }

    struct Node* temp = head;
    int count = 0;

    while (count < pos && temp != tail) {
        temp = temp->next;
        count++;
    }

    if (count != pos || temp == head) {
        printf("Position out of bounds.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == tail) {
        tail = temp->prev;
    }

    free(temp);
}

// Update data at a position
void updateAtPosition(int pos, int newData) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = tail->next;
    int count = 0;

    do {
        if (count == pos) {
            temp->data = newData;
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != tail->next);

    printf("Position out of bounds.\n");
}

// Display the list
void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = tail->next;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Free all nodes in the list
void freeList() {
    if (tail == NULL) return;

    struct Node* current = tail->next;
    struct Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != tail->next);

    tail = NULL;
}

// Example usage
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display(); // 10 20 30

    insertAtBeginning(5);
    display(); // 5 10 20 30

    insertAtPosition(25, 3);
    display(); // 5 10 20 25 30

    insertAtPosition(0, 0);
    display(); // 0 5 10 20 25 30

    updateAtPosition(2, 99);
    display(); // 0 5 99 20 25 30

    deleteFromBeginning();
    display(); // 5 99 20 25 30

    deleteFromEnd();
    display(); // 5 99 20 25

    deleteFromPosition(1);
    display(); // 5 20 25

    deleteFromPosition(10); // Invalid

    // Free memory
    freeList();
    printf("Memory cleaned up.\n");

    return 0;
}
