//Rotate an Matrix 90 Degree clockwise
//used in image processing for rotation

#include <stdio.h>
#include <stdlib.h>

// Function to rotate the matrix 90 degrees clockwise
int** rotateMatrix(int** mat, int m, int n) {
    // Allocate memory for result matrix of size n x m
    int** res = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(m * sizeof(int));
    }

    // Perform the rotation
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[j][m - i - 1] = mat[i][j];
        }
    }

    return res;
}

// Helper function to print the matrix
void printMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m = 4, n = 4;
    int** mat = (int**)malloc(m * sizeof(int*));

    int** values = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        values[i] = (int*)malloc(n * sizeof(int));
    }

    int tempValues[4][4] = {//fixed values
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            values[i][j] = tempValues[i][j];//can be user input
        }
    }

    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            mat[i][j] = values[i][j];
        }
    }

    int** res = rotateMatrix(mat, m, n);
    for (int i = 0; i < m; i++) free(values[i]);
    free(values);
    
    // Print rotated matrix (size will be n x m)
    printMatrix(res, n, m);

    // Free allocated memory
    for (int i = 0; i < m; i++) free(mat[i]);
    free(mat);

    for (int i = 0; i < n; i++) free(res[i]);
    free(res);

    return 0;
}
