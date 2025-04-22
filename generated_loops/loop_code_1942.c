#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = B[i][j] * Y[j];
            C[i][j] = Z[i] + A[i][j];
            X[i] = Z[i] * Z[i];
            X[i] = A[i][j] + Y[j];
            B[i][j] = Y[j] * Y[j];
            Z[i] = Y[j] + A[i][j];
        }
    }
    return 0;
}