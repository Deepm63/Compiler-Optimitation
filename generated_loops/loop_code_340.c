#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = X[i] - Z[i];
            Y[j] = Y[j] * Y[j];
            X[i] = B[i][j] - X[i];
            Z[i] = C[i][j] + X[i];
            B[i][j] = X[i] * B[i][j];
            A[i][j] = B[i][j] * Y[j];
            B[i][j] = X[i] * C[i][j];
            Y[j] = C[i][j] * X[i];
        }
    }
    return 0;
}