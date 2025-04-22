#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = C[i][j] * Z[i];
            A[i][j] = A[i][j] * X[i];
            Z[i] = B[i][j] * X[i];
            A[i][j] = X[i] + Z[i];
            A[i][j] = Z[i] * B[i][j];
            Y[j] = Y[j] + X[i];
            X[i] = Z[i] + C[i][j];
            X[i] = A[i][j] - A[i][j];
        }
    }
    return 0;
}