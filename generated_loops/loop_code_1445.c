#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = A[i][j] * X[i];
            X[i] = Y[j] * C[i][j];
            C[i][j] = A[i][j] + A[i][j];
            A[i][j] = B[i][j] + Y[j];
            B[i][j] = Z[i] - A[i][j];
            A[i][j] = X[i] - C[i][j];
            X[i] = Z[i] + A[i][j];
            C[i][j] = B[i][j] + B[i][j];
        }
    }
    return 0;
}