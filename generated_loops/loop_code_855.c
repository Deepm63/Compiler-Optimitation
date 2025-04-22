#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = X[i] * Y[j];
            B[i][j] = C[i][j] - Z[i];
            C[i][j] = X[i] + Z[i];
            Y[j] = B[i][j] * Y[j];
            X[i] = Z[i] - X[i];
            A[i][j] = X[i] - A[i][j];
            X[i] = Y[j] + Z[i];
            Z[i] = Z[i] * B[i][j];
        }
    }
    return 0;
}