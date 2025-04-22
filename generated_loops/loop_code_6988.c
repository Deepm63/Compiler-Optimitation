#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = B[i][j] - Z[i];
            B[i][j] = A[i][j] - C[i][j];
            Y[j] = C[i][j] * Y[j];
            B[i][j] = Y[j] + X[i];
            Z[i] = Y[j] * X[i];
            A[i][j] = C[i][j] - C[i][j];
            C[i][j] = Y[j] * X[i];
            A[i][j] = Z[i] - B[i][j];
            Y[j] = Z[i] * X[i];
        }
    }
    return 0;
}