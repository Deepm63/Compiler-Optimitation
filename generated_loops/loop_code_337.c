#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = Y[j] + C[i][j];
            Y[j] = Y[j] + B[i][j];
            X[i] = Y[j] + Y[j];
            B[i][j] = C[i][j] - A[i][j];
            C[i][j] = Y[j] + A[i][j];
            C[i][j] = Z[i] + B[i][j];
            Y[j] = X[i] + Z[i];
            A[i][j] = C[i][j] - C[i][j];
        }
    }
    return 0;
}