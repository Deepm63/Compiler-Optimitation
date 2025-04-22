#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = C[i][j] + A[i][j];
            B[i][j] = Z[i] * A[i][j];
            B[i][j] = Y[j] + X[i];
            C[i][j] = Y[j] - A[i][j];
            C[i][j] = Z[i] + C[i][j];
            A[i][j] = B[i][j] * C[i][j];
            A[i][j] = Y[j] + A[i][j];
            A[i][j] = X[i] * C[i][j];
        }
    }
    return 0;
}