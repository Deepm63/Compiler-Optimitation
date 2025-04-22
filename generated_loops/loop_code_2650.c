#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = Z[i] - Y[j];
            Y[j] = X[i] - Y[j];
            B[i][j] = X[i] + A[i][j];
            Y[j] = C[i][j] + Y[j];
            Z[i] = Z[i] - C[i][j];
            Z[i] = A[i][j] + X[i];
            X[i] = A[i][j] + Z[i];
            A[i][j] = A[i][j] - Z[i];
            Y[j] = Z[i] * A[i][j];
            Y[j] = Z[i] * X[i];
        }
    }
    return 0;
}