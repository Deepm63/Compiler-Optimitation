#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = Y[j] * C[i][j];
            B[i][j] = X[i] - Y[j];
            Y[j] = X[i] * Y[j];
            C[i][j] = Z[i] - B[i][j];
            Z[i] = X[i] * Z[i];
            B[i][j] = Y[j] * X[i];
            Y[j] = X[i] - Y[j];
            X[i] = Z[i] - C[i][j];
            Y[j] = C[i][j] - Y[j];
        }
    }
    return 0;
}