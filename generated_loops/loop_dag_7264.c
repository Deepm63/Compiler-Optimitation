#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[i] = Z[i] + C[i][j];
            X[i] = A[i][j] * C[i][j];
            Y[i] = Y[i] * A[i][j];
            Y[i] = X[i] + C[i][j];
            Y[i] = Y[i] * Z[i];
            Z[i] = A[i][j] - Y[i];
            X[i] = Y[i] + X[i];
            X[i] = Y[i] - Z[i];
        }
    }
    return 0;
}