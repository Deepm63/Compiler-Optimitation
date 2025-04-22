#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = Y[j] * X[i];
            A[i][j] = Y[j] - A[i][j];
            Y[j] = C[i][j] * Z[i];
            B[i][j] = X[i] * Z[i];
            Y[j] = Z[i] + C[i][j];
            X[i] = Z[i] - B[i][j];
        }
    }
    return 0;
}