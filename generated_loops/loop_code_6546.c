#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = X[i] * C[i][j];
            A[i][j] = B[i][j] * A[i][j];
            Y[j] = X[i] - Z[i];
            A[i][j] = X[i] + Y[j];
            A[i][j] = X[i] - Y[j];
            Z[i] = X[i] + A[i][j];
            B[i][j] = Y[j] - C[i][j];
            Y[j] = Z[i] * X[i];
            X[i] = C[i][j] - B[i][j];
        }
    }
    return 0;
}