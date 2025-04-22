#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = Y[i] * C[i][j];
            X[i] = Z[i] - X[i];
            A[i][j] = Z[i] - X[i];
            Y[i] = A[i][j] - B[i][j];
            Z[i] = A[i][j] * X[i];
            X[i] = Y[i] - Z[i];
            Z[i] = X[i] + C[i][j];
            Z[i] = Y[i] - B[i][j];
            X[i] = A[i][j] - Z[i];
        }
    }
    return 0;
}