#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = A[i][j] * C[i][j];
            Y[i] = A[i][j] * B[i][j];
            Y[i] = Y[i] * Z[i];
            A[i][j] = Y[i] - Z[i];
            X[i] = B[i][j] * Y[i];
            Y[i] = Y[i] * X[i];
            B[i][j] = Y[i] + Z[i];
        }
    }
    return 0;
}