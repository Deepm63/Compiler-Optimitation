#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = C[i][j] * A[i][j];
            Z[i] = B[i][j] - A[i][j];
            Y[i] = B[i][j] + A[i][j];
            Y[i] = B[i][j] - A[i][j];
            Y[i] = Y[i] + X[i];
            B[i][j] = C[i][j] * Y[i];
            X[i] = C[i][j] + X[i];
            B[i][j] = Z[i] - X[i];
            X[i] = C[i][j] * A[i][j];
            C[i][j] = Y[i] + X[i];
        }
    }
    return 0;
}