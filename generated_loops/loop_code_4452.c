#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Y[j] + Y[j];
            Y[j] = C[i][j] * A[i][j];
            Y[j] = X[i] - A[i][j];
            B[i][j] = A[i][j] * X[i];
            X[i] = Z[i] * Y[j];
            X[i] = X[i] - Z[i];
            Z[i] = C[i][j] * X[i];
            B[i][j] = Y[j] - B[i][j];
        }
    }
    return 0;
}