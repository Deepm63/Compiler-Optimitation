#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    X[ii] = B[ii][jj] + A[ii][jj];
                                X[ii] = A[ii][jj] + Z[ii];
                                X[ii] = Y[ii] * A[ii][jj];
                                X[ii] = Z[ii] + X[ii];
                                X[ii] = X[ii] * C[ii][jj];
                                X[ii] = Z[ii] - X[ii];
                                X[ii] = A[ii][jj] + Z[ii];
                }
            }
        }
    }
    return 0;
}