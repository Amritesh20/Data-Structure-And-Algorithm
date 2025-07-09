#include <stdio.h>
#define MAX_SIZE 100

// Heap array and size
int heap[MAX_SIZE];
int heapSize = 0;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert a new element into the heap
void insert(int value) {
    if (heapSize == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    // Place at the end
    int i = heapSize;
    heap[i] = value;
    heapSize++;

    // Heapify up
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down from index i
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;

    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Remove and return the maximum element
int extractMax() {
    if (heapSize <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(0);

    return root;
}

// Display the heap array
void displayHeap() {
    printf("Heap elements: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main function to test the heap
int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(40);
    insert(50);

    displayHeap();

    printf("Extracted max: %d\n", extractMax());
    displayHeap();

    printf("Extracted max: %d\n", extractMax());
    displayHeap();

    return 0;
}
