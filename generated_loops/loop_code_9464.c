#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = Z[i] - A[i][j];
            Z[i] = B[i][j] + Z[i];
            Y[j] = C[i][j] * X[i];
            X[i] = B[i][j] * C[i][j];
            A[i][j] = Z[i] * B[i][j];
            Y[j] = Z[i] + Z[i];
            A[i][j] = X[i] * Y[j];
            Z[i] = B[i][j] - C[i][j];
        }
    }
    return 0;
}