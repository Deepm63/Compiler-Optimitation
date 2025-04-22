#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = C[i][j] * Y[j];
            Z[i] = Z[i] - X[i];
            X[i] = Y[j] * Y[j];
            B[i][j] = A[i][j] * Y[j];
            B[i][j] = Z[i] * A[i][j];
            A[i][j] = X[i] - C[i][j];
            Z[i] = Y[j] - A[i][j];
            X[i] = Z[i] * A[i][j];
            C[i][j] = X[i] + X[i];
        }
    }
    return 0;
}