#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = A[i][j] + A[i][j];
            C[i][j] = B[i][j] * B[i][j];
            Z[i] = X[i] - Z[i];
            A[i][j] = Z[i] + X[i];
            C[i][j] = Z[i] + C[i][j];
            Z[i] = Z[i] * A[i][j];
            X[i] = B[i][j] * A[i][j];
            Z[i] = A[i][j] + Z[i];
            B[i][j] = X[i] + Y[j];
            A[i][j] = Z[i] * Z[i];
        }
    }
    return 0;
}