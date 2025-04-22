#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = C[i][j] + A[i][j];
            Y[j] = Z[i] - X[i];
            Z[i] = Z[i] + Z[i];
            C[i][j] = Z[i] - B[i][j];
            X[i] = C[i][j] + C[i][j];
            Z[i] = B[i][j] + Z[i];
        }
    }
    return 0;
}