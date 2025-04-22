#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[i] = A[i][j] - C[i][j];
            Z[i] = Y[i] + X[i];
            X[i] = A[i][j] * Z[i];
            Y[i] = A[i][j] * Z[i];
            A[i][j] = Y[i] - X[i];
            A[i][j] = Y[i] - X[i];
            A[i][j] = B[i][j] * X[i];
        }
    }
    return 0;
}