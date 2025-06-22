#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ------------------------ Linked List ------------------------

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertList(Node* head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

Node* extractMaxList(Node* head, int* maxVal) {
    if (!head) return NULL;

    Node *maxNode = head, *prev = NULL, *temp = head, *prevMax = NULL;

    while (temp->next) {
        if (temp->next->data > maxNode->data) {
            maxNode = temp->next;
            prevMax = temp;
        }
        temp = temp->next;
    }

    *maxVal = maxNode->data;

    if (maxNode == head)
        head = head->next;
    else
        prevMax->next = maxNode->next;

    free(maxNode);
    return head;
}

void printList(Node* head) {
    printf("Linked List PQ: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// ------------------------ Max-Heap (Array) ------------------------

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;
    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

void insertHeap(int val) {
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

int extractMaxHeap() {
    if (heapSize == 0) return -1;
    int maxVal = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return maxVal;
}

void printHeap() {
    printf("Heap PQ: ");
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// ------------------------ Sorted Array ------------------------

int arr[MAX];
int count = 0;

void insertSorted(int val) {
    int i = count - 1;
    while (i >= 0 && arr[i] < val) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = val;
    count++;
}

int extractMaxSorted() {
    if (count == 0) return -1;
    return arr[--count];
}

void printArray() {
    printf("Sorted Array PQ: ");
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ------------------------ Main Function ------------------------

int main() {
    printf("---- Max Priority Queue Using Linked List ----\n");
    Node* listPQ = NULL;
    listPQ = insertList(listPQ, 10);
    listPQ = insertList(listPQ, 30);
    listPQ = insertList(listPQ, 20);
    printList(listPQ);
    int maxValList;
    listPQ = extractMaxList(listPQ, &maxValList);
    printf("Extracted Max from List: %d\n", maxValList);
    printList(listPQ);

    printf("\n---- Max Priority Queue Using Max-Heap ----\n");
    insertHeap(10);
    insertHeap(30);
    insertHeap(20);
    printHeap();
    int maxValHeap = extractMaxHeap();
    printf("Extracted Max from Heap: %d\n", maxValHeap);
    printHeap();

    printf("\n---- Max Priority Queue Using Sorted Array ----\n");
    insertSorted(10);
    insertSorted(30);
    insertSorted(20);
    printArray();
    int maxValArray = extractMaxSorted();
    printf("Extracted Max from Array: %d\n", maxValArray);
    printArray();

    return 0;
}
