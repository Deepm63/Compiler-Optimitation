#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = X[i] + X[i];
            X[i] = A[i][j] * X[i];
            Y[j] = C[i][j] - Z[i];
            B[i][j] = B[i][j] * B[i][j];
            B[i][j] = A[i][j] * X[i];
            Z[i] = X[i] - C[i][j];
        }
    }
    return 0;
}