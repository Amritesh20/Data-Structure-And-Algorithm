//Marge Sort on Link List.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* getMiddle(Node* head) {
    if (!head) return head;
    Node* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* mid = getMiddle(head);
    Node* nextToMid = mid->next;
    mid->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMid);

    return merge(left, right);
}

// Example usage
int main() {
    Node* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);

    printf("Original List: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
