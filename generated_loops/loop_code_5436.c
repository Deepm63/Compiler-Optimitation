#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Y[j] - Z[i];
            Y[j] = C[i][j] * X[i];
            Y[j] = Z[i] + X[i];
            X[i] = B[i][j] + B[i][j];
            X[i] = A[i][j] * Y[j];
            B[i][j] = Y[j] - Y[j];
        }
    }
    return 0;
}