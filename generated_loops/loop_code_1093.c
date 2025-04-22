#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[j] = Y[j] + Y[j];
            A[i][j] = X[i] - Z[i];
            Z[i] = C[i][j] * B[i][j];
            B[i][j] = B[i][j] * A[i][j];
            A[i][j] = A[i][j] - A[i][j];
            X[i] = Y[j] - X[i];
            Z[i] = A[i][j] * A[i][j];
        }
    }
    return 0;
}