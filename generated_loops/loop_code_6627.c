#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = X[i] + X[i];
            Z[i] = B[i][j] * Z[i];
            X[i] = C[i][j] - C[i][j];
            A[i][j] = A[i][j] + B[i][j];
            Z[i] = B[i][j] * A[i][j];
            Y[j] = C[i][j] * X[i];
            X[i] = B[i][j] + A[i][j];
            Y[j] = X[i] * X[i];
            Y[j] = A[i][j] - Y[j];
        }
    }
    return 0;
}