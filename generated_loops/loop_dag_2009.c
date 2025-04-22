#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = B[i][j] - Y[i];
            C[i][j] = Z[i] - X[i];
            X[i] = B[i][j] - C[i][j];
            Z[i] = X[i] - C[i][j];
            X[i] = A[i][j] - Z[i];
            C[i][j] = Z[i] + X[i];
            Z[i] = X[i] - C[i][j];
            C[i][j] = Z[i] - X[i];
        }
    }
    return 0;
}