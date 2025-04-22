#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = B[i][j] * Z[i];
            X[i] = Y[j] - C[i][j];
            Z[i] = Y[j] * B[i][j];
            A[i][j] = Y[j] + X[i];
            B[i][j] = Z[i] * X[i];
            X[i] = Z[i] + X[i];
            X[i] = A[i][j] - Y[j];
            Z[i] = C[i][j] + Y[j];
            A[i][j] = X[i] * A[i][j];
            X[i] = X[i] - Y[j];
        }
    }
    return 0;
}