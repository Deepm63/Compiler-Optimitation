#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Y[i] - A[i][j];
            X[i] = X[i] - C[i][j];
            Z[i] = Y[i] * X[i];
            Z[i] = A[i][j] + X[i];
            X[i] = Z[i] - X[i];
            Z[i] = A[i][j] * X[i];
            Z[i] = A[i][j] * X[i];
            X[i] = Y[i] * Z[i];
        }
    }
    return 0;
}