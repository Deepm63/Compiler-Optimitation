#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = Z[i] * X[i];
            X[i] = X[i] * A[i][j];
            Y[j] = X[i] - C[i][j];
            A[i][j] = X[i] * Y[j];
            Z[i] = Z[i] + A[i][j];
            X[i] = Z[i] + Z[i];
        }
    }
    return 0;
}