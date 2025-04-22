#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = Z[i] * X[i];
            B[i][j] = Z[i] + X[i];
            Z[i] = A[i][j] * X[i];
            X[i] = Z[i] + Y[j];
            Y[j] = X[i] - X[i];
            Y[j] = B[i][j] - Y[j];
            B[i][j] = X[i] - Y[j];
        }
    }
    return 0;
}