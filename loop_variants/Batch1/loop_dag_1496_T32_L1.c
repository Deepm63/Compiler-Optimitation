#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 32;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    Y[ii] = B[ii][jj] + X[ii];
                                A[ii][jj] = Y[ii] - C[ii][jj];
                                B[ii][jj] = Z[ii] * X[ii];
                                B[ii][jj] = Y[ii] + C[ii][jj];
                                C[ii][jj] = B[ii][jj] + A[ii][jj];
                                C[ii][jj] = A[ii][jj] - Z[ii];
                                Z[ii] = A[ii][jj] * X[ii];
                                A[ii][jj] = B[ii][jj] + Z[ii];
                                A[ii][jj] = A[ii][jj] - C[ii][jj];
                }
            }
        }
    }
    return 0;
}