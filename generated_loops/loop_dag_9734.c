#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = Y[i] * Z[i];
            A[i][j] = B[i][j] - C[i][j];
            A[i][j] = A[i][j] - Z[i];
            B[i][j] = A[i][j] + Y[i];
            A[i][j] = B[i][j] + Y[i];
            B[i][j] = A[i][j] - Z[i];
            Y[i] = X[i] + C[i][j];
            Y[i] = A[i][j] * Z[i];
            Y[i] = A[i][j] + X[i];
            Y[i] = A[i][j] - Y[i];
        }
    }
    return 0;
}