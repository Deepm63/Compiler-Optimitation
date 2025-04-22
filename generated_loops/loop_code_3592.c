#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = Y[j] + X[i];
            Y[j] = B[i][j] + Z[i];
            Z[i] = Y[j] * A[i][j];
            Z[i] = A[i][j] - X[i];
            X[i] = B[i][j] * Z[i];
            Y[j] = C[i][j] + Z[i];
            A[i][j] = Y[j] * B[i][j];
            Y[j] = Z[i] - C[i][j];
            C[i][j] = B[i][j] * Z[i];
            B[i][j] = Z[i] - X[i];
        }
    }
    return 0;
}