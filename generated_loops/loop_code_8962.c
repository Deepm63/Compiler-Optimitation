#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + A[i][j];
            C[i][j] = X[i] - Z[i];
            C[i][j] = Z[i] + B[i][j];
            B[i][j] = X[i] + B[i][j];
            Y[j] = C[i][j] - A[i][j];
            A[i][j] = Z[i] * Z[i];
        }
    }
    return 0;
}