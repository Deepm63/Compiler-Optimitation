#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 128;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int ii = T * j; ii < T * j + T; ii++) {
                for (int jj = T * i; jj < T * i + T; jj++) {
                    A[ii][jj] = B[ii][jj] + X[ii];
                                B[ii][jj] = Y[ii] + A[ii][jj];
                                Y[ii] = A[ii][jj] - Z[ii];
                                B[ii][jj] = Y[ii] + A[ii][jj];
                                A[ii][jj] = B[ii][jj] + X[ii];
                                Y[ii] = Y[ii] + B[ii][jj];
                                Z[ii] = Y[ii] * A[ii][jj];
                                Y[ii] = Z[ii] - X[ii];
                                Y[ii] = B[ii][jj] - Z[ii];
                                Y[ii] = Y[ii] * B[ii][jj];
                }
            }
        }
    }
    return 0;
}