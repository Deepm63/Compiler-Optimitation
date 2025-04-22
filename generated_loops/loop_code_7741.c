#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = B[i][j] * B[i][j];
            Y[j] = A[i][j] + Z[i];
            Y[j] = X[i] + X[i];
            A[i][j] = Y[j] * B[i][j];
            Z[i] = X[i] - X[i];
            Y[j] = Z[i] - B[i][j];
            Z[i] = X[i] + C[i][j];
            A[i][j] = A[i][j] + Z[i];
            Z[i] = Z[i] + B[i][j];
            X[i] = Y[j] - Y[j];
        }
    }
    return 0;
}