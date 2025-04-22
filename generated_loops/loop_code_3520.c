#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = C[i][j] - X[i];
            X[i] = B[i][j] * X[i];
            B[i][j] = Z[i] - B[i][j];
            X[i] = A[i][j] - C[i][j];
            B[i][j] = X[i] - A[i][j];
            B[i][j] = Y[j] - X[i];
            B[i][j] = C[i][j] - Y[j];
            Z[i] = Y[j] - X[i];
            Z[i] = Z[i] + C[i][j];
        }
    }
    return 0;
}