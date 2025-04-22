#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + X[i];
            C[i][j] = X[i] * A[i][j];
            C[i][j] = A[i][j] - C[i][j];
            Z[i] = B[i][j] + A[i][j];
            B[i][j] = Z[i] * X[i];
            A[i][j] = X[i] - Z[i];
            B[i][j] = A[i][j] - Y[j];
        }
    }
    return 0;
}