#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = X[i] * B[i][j];
            C[i][j] = Y[j] + Z[i];
            Y[j] = Y[j] - C[i][j];
            Z[i] = A[i][j] * X[i];
            Y[j] = X[i] - C[i][j];
            Y[j] = B[i][j] + B[i][j];
            A[i][j] = A[i][j] - A[i][j];
        }
    }
    return 0;
}