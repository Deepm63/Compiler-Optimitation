#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = Y[j] + Z[i];
            C[i][j] = B[i][j] - B[i][j];
            Y[j] = A[i][j] * C[i][j];
            X[i] = Y[j] * X[i];
            C[i][j] = B[i][j] - C[i][j];
            Z[i] = X[i] + X[i];
            X[i] = X[i] - X[i];
            Y[j] = C[i][j] * C[i][j];
        }
    }
    return 0;
}