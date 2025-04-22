#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = A[i][j] - X[i];
            Z[i] = B[i][j] * X[i];
            Z[i] = Y[i] - C[i][j];
            B[i][j] = Z[i] - X[i];
            Z[i] = Y[i] + C[i][j];
            B[i][j] = Y[i] + Z[i];
            Z[i] = B[i][j] * Y[i];
            Y[i] = B[i][j] - Z[i];
        }
    }
    return 0;
}