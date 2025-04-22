#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = Y[i] * X[i];
            X[i] = A[i][j] * C[i][j];
            Y[i] = B[i][j] - Z[i];
            X[i] = B[i][j] * Z[i];
            Z[i] = B[i][j] * Y[i];
            X[i] = Y[i] + Z[i];
            B[i][j] = Y[i] - A[i][j];
            X[i] = Z[i] + X[i];
            Z[i] = X[i] - C[i][j];
            X[i] = Z[i] - C[i][j];
        }
    }
    return 0;
}