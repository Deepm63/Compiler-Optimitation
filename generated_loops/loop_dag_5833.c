#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Y[i] - Z[i];
            C[i][j] = Y[i] + A[i][j];
            X[i] = Y[i] + X[i];
            Y[i] = Z[i] * X[i];
            Y[i] = B[i][j] * X[i];
            Y[i] = Y[i] * C[i][j];
            Y[i] = Y[i] * Z[i];
        }
    }
    return 0;
}