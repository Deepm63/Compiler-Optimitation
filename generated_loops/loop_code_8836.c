#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j] * A[i][j];
            Y[j] = A[i][j] - X[i];
            Y[j] = A[i][j] * Z[i];
            Y[j] = X[i] - Z[i];
            X[i] = X[i] * C[i][j];
            B[i][j] = Z[i] - Y[j];
            X[i] = Y[j] - Y[j];
            A[i][j] = X[i] - Z[i];
        }
    }
    return 0;
}