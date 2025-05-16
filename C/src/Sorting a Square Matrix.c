// This program sorts a square matrix using bubble sort.
// It first flattens the matrix into a 1D array, sorts it, and then copies the sorted values back into the matrix.      
// The matrix is printed before and after sorting.

#include <stdio.h>

#define ROWS 3
#define COLS 3

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {9, 7, 5},
        {1, 3, 2},
        {6, 8, 4}
    };

    printf("Original matrix:\n");
    printMatrix(matrix);

    // Flatten the matrix into a 1D array
    int size = ROWS * COLS;
    int flat[ROWS * COLS];
    int k = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            flat[k++] = matrix[i][j];
        }
    }

    // Sort the flattened array using bubble sort
    bubbleSort(flat, size);

    // Copy sorted values back into the matrix
    k = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = flat[k++];
        }
    }

    // Print the sorted matrix
    printf("Sorted matrix:\n");
    printMatrix(matrix);

    return 0;
}
