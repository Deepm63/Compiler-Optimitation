#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = B[i][j] - X[i];
            X[i] = B[i][j] * A[i][j];
            X[i] = Y[i] * B[i][j];
            X[i] = B[i][j] - Y[i];
            Y[i] = B[i][j] * X[i];
            Y[i] = Y[i] * X[i];
            X[i] = Y[i] - C[i][j];
            B[i][j] = Y[i] * X[i];
            Y[i] = Z[i] * X[i];
        }
    }
    return 0;
}