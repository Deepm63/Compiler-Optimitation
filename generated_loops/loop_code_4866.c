#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = Y[j] + B[i][j];
            A[i][j] = B[i][j] * C[i][j];
            Y[j] = Z[i] - Z[i];
            Y[j] = Z[i] * X[i];
            X[i] = Z[i] * Y[j];
            Z[i] = Z[i] - B[i][j];
        }
    }
    return 0;
}