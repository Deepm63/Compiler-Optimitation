#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int ii = T * j; ii < T * j + T; ii++) {
                for (int jj = T * i; jj < T * i + T; jj++) {
                    Y[ii] = Y[ii] * Z[ii];
                                B[ii][jj] = Z[ii] + C[ii][jj];
                                X[ii] = A[ii][jj] - Z[ii];
                                X[ii] = B[ii][jj] + X[ii];
                                C[ii][jj] = A[ii][jj] + X[ii];
                                X[ii] = Y[ii] - B[ii][jj];
                                Y[ii] = B[ii][jj] + Z[ii];
                                X[ii] = Y[ii] * Z[ii];
                                Z[ii] = A[ii][jj] * X[ii];
                                X[ii] = Y[ii] - Z[ii];
                }
            }
        }
    }
    return 0;
}