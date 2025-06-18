#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* tail = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at a given position (0-based index)
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

    if (tail == head) { // Single node
        free(tail);
        tail = NULL;
    } else {
        tail->next = head->next;
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
        return;
    }

    struct Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    temp->next = head;
    free(tail);
    tail = temp;
}

// Delete from any position (0-based index)
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

    while (count < pos - 1 && temp->next != tail->next) {
        temp = temp->next;
        count++;
    }

    if (temp->next == tail->next || count != pos - 1) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;

    if (toDelete == tail) {
        tail = temp;
    }

    free(toDelete);
}

// Update node at position
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
    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\n");
}

// Free the entire list
void freeList() {
    if (tail == NULL) return;

    struct Node* head = tail->next;
    struct Node* temp = head;

    do {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);

    tail = NULL;
}

// Driver code
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

    // Clean up memory
    freeList();

    return 0;
}
