#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = Y[j] - C[i][j];
            Y[j] = Y[j] * Z[i];
            B[i][j] = B[i][j] - C[i][j];
            B[i][j] = Z[i] * Y[j];
            B[i][j] = B[i][j] - X[i];
            B[i][j] = Y[j] * A[i][j];
            X[i] = A[i][j] - Z[i];
            Z[i] = A[i][j] + Y[j];
            Z[i] = Z[i] + A[i][j];
            B[i][j] = B[i][j] + Y[j];
        }
    }
    return 0;
}