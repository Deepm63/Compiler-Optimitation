#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = C[i][j] * Y[j];
            Y[j] = X[i] - Y[j];
            Z[i] = X[i] * B[i][j];
            Y[j] = Z[i] - B[i][j];
            Z[i] = B[i][j] - X[i];
            C[i][j] = X[i] + A[i][j];
            C[i][j] = Z[i] + Z[i];
            C[i][j] = Y[j] * X[i];
            Y[j] = Y[j] + A[i][j];
        }
    }
    return 0;
}