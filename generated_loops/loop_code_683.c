#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = Z[i] + B[i][j];
            Y[j] = X[i] - Y[j];
            Y[j] = X[i] - Y[j];
            A[i][j] = Y[j] * Z[i];
            Y[j] = Y[j] - X[i];
            C[i][j] = Z[i] * Z[i];
            B[i][j] = Z[i] * Z[i];
            C[i][j] = C[i][j] - A[i][j];
            A[i][j] = A[i][j] - X[i];
        }
    }
    return 0;
}