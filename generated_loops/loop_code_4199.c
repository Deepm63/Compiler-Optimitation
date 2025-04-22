#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = X[i] * Z[i];
            Y[j] = B[i][j] - Y[j];
            Y[j] = Z[i] + A[i][j];
            A[i][j] = B[i][j] * B[i][j];
            X[i] = X[i] + B[i][j];
            X[i] = X[i] + X[i];
            Z[i] = Y[j] + X[i];
            X[i] = A[i][j] + A[i][j];
            C[i][j] = Y[j] + B[i][j];
        }
    }
    return 0;
}