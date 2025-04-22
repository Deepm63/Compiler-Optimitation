#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = X[i] + A[i][j];
            X[i] = Z[i] - B[i][j];
            B[i][j] = A[i][j] - A[i][j];
            Y[j] = C[i][j] + X[i];
            Y[j] = X[i] * X[i];
            Y[j] = Z[i] * A[i][j];
            A[i][j] = A[i][j] + Z[i];
            Z[i] = X[i] * B[i][j];
        }
    }
    return 0;
}