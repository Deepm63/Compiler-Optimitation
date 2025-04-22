#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = B[i][j] + A[i][j];
            X[i] = A[i][j] + Z[i];
            Y[i] = A[i][j] + X[i];
            X[i] = B[i][j] + A[i][j];
            X[i] = A[i][j] + X[i];
            X[i] = Y[i] - A[i][j];
        }
    }
    return 0;
}