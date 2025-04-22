#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = Z[i] - B[i][j];
            A[i][j] = X[i] + C[i][j];
            Z[i] = Z[i] * A[i][j];
            X[i] = A[i][j] + Y[j];
            C[i][j] = X[i] + Y[j];
            Y[j] = Y[j] + Z[i];
        }
    }
    return 0;
}