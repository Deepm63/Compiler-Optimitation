#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = C[i][j] * Z[i];
            B[i][j] = Y[j] * Z[i];
            Y[j] = Y[j] - Z[i];
            A[i][j] = Y[j] + Y[j];
            Y[j] = Z[i] + A[i][j];
            Y[j] = A[i][j] + A[i][j];
            C[i][j] = B[i][j] * B[i][j];
            Y[j] = Z[i] + Z[i];
            B[i][j] = Z[i] - A[i][j];
            A[i][j] = C[i][j] - Y[j];
        }
    }
    return 0;
}