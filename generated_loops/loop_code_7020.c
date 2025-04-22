#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = Z[i] - B[i][j];
            X[i] = Z[i] + X[i];
            B[i][j] = C[i][j] + A[i][j];
            A[i][j] = B[i][j] + A[i][j];
            Y[j] = Y[j] + A[i][j];
            C[i][j] = Y[j] * Z[i];
            Z[i] = X[i] - X[i];
            Z[i] = Y[j] + Z[i];
        }
    }
    return 0;
}