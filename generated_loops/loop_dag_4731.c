#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = B[i][j] - X[i];
            Y[i] = B[i][j] * X[i];
            B[i][j] = Y[i] * Z[i];
            Y[i] = A[i][j] - C[i][j];
            C[i][j] = B[i][j] * X[i];
            C[i][j] = Y[i] + X[i];
            C[i][j] = Y[i] * Z[i];
            C[i][j] = Y[i] + A[i][j];
        }
    }
    return 0;
}