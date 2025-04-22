#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = X[i] - B[i][j];
            Y[j] = B[i][j] + Y[j];
            X[i] = A[i][j] * B[i][j];
            X[i] = Z[i] + X[i];
            B[i][j] = C[i][j] * Z[i];
            A[i][j] = B[i][j] * X[i];
            Z[i] = Y[j] + A[i][j];
            Z[i] = X[i] + Z[i];
        }
    }
    return 0;
}