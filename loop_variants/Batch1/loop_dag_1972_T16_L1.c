#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    B[ii][jj] = Y[ii] - Z[ii];
                                A[ii][jj] = X[ii] * C[ii][jj];
                                B[ii][jj] = Y[ii] - Z[ii];
                                C[ii][jj] = B[ii][jj] + Z[ii];
                                X[ii] = B[ii][jj] - A[ii][jj];
                                X[ii] = B[ii][jj] * Y[ii];
                                B[ii][jj] = Z[ii] * X[ii];
                                X[ii] = B[ii][jj] + A[ii][jj];
                                B[ii][jj] = B[ii][jj] - Z[ii];
                }
            }
        }
    }
    return 0;
}