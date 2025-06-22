#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ----------------- Bubble Sort -----------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// ----------------- Selection Sort -----------------
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// ----------------- Insertion Sort -----------------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// ----------------- Merge Sort -----------------
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge temp arrays back into arr[]
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// ----------------- Driver Code -----------------
void runSorts(int arr[], int n) {
    int temp[100];

    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Bubble Sort
    memcpy(temp, arr, n * sizeof(int));
    bubbleSort(temp, n);
    printf("\nBubble Sort:\n");
    printArray(temp, n);

    // Selection Sort
    memcpy(temp, arr, n * sizeof(int));
    selectionSort(temp, n);
    printf("\nSelection Sort:\n");
    printArray(temp, n);

    // Insertion Sort
    memcpy(temp, arr, n * sizeof(int));
    insertionSort(temp, n);
    printf("\nInsertion Sort:\n");
    printArray(temp, n);

    // Merge Sort
    memcpy(temp, arr, n * sizeof(int));
    mergeSort(temp, 0, n - 1);
    printf("\nMerge Sort:\n");
    printArray(temp, n);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    runSorts(arr, n);

    return 0;
}
