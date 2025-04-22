#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = Y[j] - C[i][j];
            Y[j] = C[i][j] - C[i][j];
            Z[i] = X[i] * Z[i];
            X[i] = A[i][j] - Y[j];
            B[i][j] = B[i][j] - C[i][j];
            C[i][j] = C[i][j] - Y[j];
            X[i] = Z[i] * A[i][j];
            C[i][j] = Z[i] + A[i][j];
        }
    }
    return 0;
}