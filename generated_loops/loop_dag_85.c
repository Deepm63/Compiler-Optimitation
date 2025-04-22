#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Y[i] * Z[i];
            Y[i] = X[i] - C[i][j];
            X[i] = B[i][j] + Z[i];
            X[i] = B[i][j] * C[i][j];
            X[i] = A[i][j] + X[i];
            X[i] = Y[i] + X[i];
            X[i] = Y[i] - C[i][j];
        }
    }
    return 0;
}