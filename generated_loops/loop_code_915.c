#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = X[i] - Z[i];
            Y[j] = B[i][j] + Z[i];
            A[i][j] = C[i][j] - Y[j];
            X[i] = C[i][j] - C[i][j];
            X[i] = B[i][j] - Y[j];
            B[i][j] = Z[i] * Z[i];
            X[i] = B[i][j] - C[i][j];
            X[i] = Y[j] + X[i];
        }
    }
    return 0;
}