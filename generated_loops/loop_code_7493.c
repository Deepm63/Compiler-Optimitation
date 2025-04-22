#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = X[i] - Y[j];
            B[i][j] = Z[i] + A[i][j];
            B[i][j] = X[i] * X[i];
            C[i][j] = X[i] + Y[j];
            B[i][j] = X[i] - Z[i];
            B[i][j] = Z[i] * B[i][j];
        }
    }
    return 0;
}