#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = A[i][j] * B[i][j];
            Z[i] = Z[i] + Y[j];
            Z[i] = X[i] - C[i][j];
            Z[i] = Y[j] + C[i][j];
            B[i][j] = C[i][j] + Z[i];
            Z[i] = X[i] * C[i][j];
            A[i][j] = B[i][j] * A[i][j];
        }
    }
    return 0;
}