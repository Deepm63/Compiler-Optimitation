#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = X[i] * C[i][j];
            X[i] = A[i][j] * A[i][j];
            B[i][j] = B[i][j] * C[i][j];
            X[i] = B[i][j] * Z[i];
            X[i] = Y[j] - A[i][j];
            X[i] = Y[j] - X[i];
        }
    }
    return 0;
}