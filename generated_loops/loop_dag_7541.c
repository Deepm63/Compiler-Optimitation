#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = A[i][j] - X[i];
            X[i] = B[i][j] + Y[i];
            Y[i] = A[i][j] - Z[i];
            Z[i] = A[i][j] - Z[i];
            C[i][j] = Y[i] + Z[i];
            C[i][j] = Y[i] * X[i];
            Y[i] = X[i] * C[i][j];
            Y[i] = X[i] + C[i][j];
        }
    }
    return 0;
}