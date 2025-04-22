#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = A[i][j] + C[i][j];
            C[i][j] = B[i][j] - X[i];
            Z[i] = Y[i] + Z[i];
            Y[i] = Z[i] + C[i][j];
            Y[i] = X[i] - C[i][j];
            Z[i] = Y[i] * C[i][j];
            C[i][j] = Y[i] + Z[i];
            Z[i] = Y[i] + Z[i];
        }
    }
    return 0;
}