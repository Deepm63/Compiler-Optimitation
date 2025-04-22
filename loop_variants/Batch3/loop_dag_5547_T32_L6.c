#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 32;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    X[i] = Y[i] + Z[i];
                                Z[i] = Y[i] - A[i][ii];
                                A[i][ii] = Z[i] * X[i];
                                Z[i] = X[i] - C[i][ii];
                                Z[i] = B[i][ii] - X[i];
                                B[i][ii] = A[i][ii] - Z[i];
                                C[i][ii] = B[i][ii] - X[i];
                }
            }
        }
    }
    return 0;
}