#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = X[i] * Y[j];
            Z[i] = Z[i] * Y[j];
            Y[j] = X[i] + C[i][j];
            X[i] = C[i][j] * X[i];
            Z[i] = A[i][j] - Y[j];
            B[i][j] = Z[i] * B[i][j];
            X[i] = Y[j] + X[i];
            Z[i] = X[i] - B[i][j];
        }
    }
    return 0;
}