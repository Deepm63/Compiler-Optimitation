#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = B[i][j] - Z[i];
            A[i][j] = B[i][j] * X[i];
            B[i][j] = Z[i] - Y[j];
            X[i] = Z[i] - Y[j];
            B[i][j] = Y[j] - C[i][j];
            Y[j] = C[i][j] * Z[i];
            Y[j] = Z[i] + X[i];
            Y[j] = X[i] - Y[j];
            B[i][j] = A[i][j] * X[i];
            X[i] = B[i][j] * B[i][j];
        }
    }
    return 0;
}