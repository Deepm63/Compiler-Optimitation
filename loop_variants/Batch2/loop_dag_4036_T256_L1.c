#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    Y[ii] = A[ii][jj] + X[ii];
                                X[ii] = Y[ii] * C[ii][jj];
                                Z[ii] = B[ii][jj] + Z[ii];
                                Y[ii] = Y[ii] - Z[ii];
                                Y[ii] = Y[ii] + Z[ii];
                                X[ii] = Y[ii] + A[ii][jj];
                                Y[ii] = B[ii][jj] - X[ii];
                }
            }
        }
    }
    return 0;
}