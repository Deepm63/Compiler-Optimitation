#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = Y[i] + Z[i];
            X[i] = Z[i] - C[i][j];
            Y[i] = X[i] - C[i][j];
            Y[i] = Z[i] + C[i][j];
            C[i][j] = B[i][j] + Y[i];
            Y[i] = B[i][j] - C[i][j];
        }
    }
    return 0;
}