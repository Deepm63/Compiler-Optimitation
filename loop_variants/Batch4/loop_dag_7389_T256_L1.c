#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    Y[ii] = A[ii][jj] * Z[ii];
                                Y[ii] = Y[ii] + Z[ii];
                                A[ii][jj] = B[ii][jj] - Z[ii];
                                Y[ii] = Y[ii] - Z[ii];
                                A[ii][jj] = Y[ii] + X[ii];
                                B[ii][jj] = X[ii] * C[ii][jj];
                                A[ii][jj] = Y[ii] - B[ii][jj];
                                Y[ii] = Z[ii] + X[ii];
                                Z[ii] = Y[ii] * B[ii][jj];
                                Z[ii] = A[ii][jj] + Y[ii];
                }
            }
        }
    }
    return 0;
}