#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = Y[j] * X[i];
            Y[j] = B[i][j] * C[i][j];
            A[i][j] = A[i][j] * Y[j];
            Y[j] = C[i][j] * C[i][j];
            Y[j] = Y[j] + Z[i];
            Z[i] = B[i][j] * Y[j];
            C[i][j] = Y[j] * Y[j];
            C[i][j] = Y[j] + C[i][j];
            C[i][j] = C[i][j] * A[i][j];
        }
    }
    return 0;
}