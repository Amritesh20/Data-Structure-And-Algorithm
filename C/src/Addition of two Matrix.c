//this program is to add two matrices

#include <stdio.h>
#include <stdlib.h>

#define N 4  // Number of rows
#define M 3  // Number of columns

void add(int A[][M], int B[][M], int C[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int A[N][M] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4} };
    int B[N][M] = { {8,8,8}, {4,4,4}, {3, 3, 3}, {5,5,5} };
    int C[N][M];

    add(A, B, C);

    printf("Result matrix is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}