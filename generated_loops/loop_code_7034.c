#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = X[i] * X[i];
            X[i] = Y[j] - Y[j];
            Z[i] = X[i] + A[i][j];
            Z[i] = Z[i] + Y[j];
            Z[i] = C[i][j] * C[i][j];
            X[i] = Z[i] * A[i][j];
            Z[i] = Z[i] + B[i][j];
        }
    }
    return 0;
}