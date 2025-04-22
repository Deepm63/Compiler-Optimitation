#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = Z[i] + Y[j];
            Z[i] = Y[j] - B[i][j];
            Z[i] = C[i][j] * A[i][j];
            Y[j] = X[i] * C[i][j];
            B[i][j] = X[i] * A[i][j];
            X[i] = Z[i] - A[i][j];
        }
    }
    return 0;
}