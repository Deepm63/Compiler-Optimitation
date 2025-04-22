#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Y[j] - Y[j];
            X[i] = C[i][j] * B[i][j];
            Z[i] = X[i] * A[i][j];
            Z[i] = X[i] - Z[i];
            Z[i] = Z[i] * Z[i];
            A[i][j] = B[i][j] * B[i][j];
            B[i][j] = Y[j] - B[i][j];
            B[i][j] = Y[j] + Z[i];
        }
    }
    return 0;
}