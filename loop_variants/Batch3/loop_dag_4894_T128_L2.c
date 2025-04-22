#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 128;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int jj = T * i; jj < T * i + T; jj++) {
                for (int ii = T * j; ii < T * j + T; ii++) {
                    X[jj] = Y[jj] - B[jj][ii];
                                Y[jj] = Z[jj] - C[jj][ii];
                                B[jj][ii] = Y[jj] * C[jj][ii];
                                B[jj][ii] = Y[jj] - C[jj][ii];
                                B[jj][ii] = B[jj][ii] * A[jj][ii];
                                Y[jj] = Y[jj] * X[jj];
                                B[jj][ii] = Y[jj] + X[jj];
                }
            }
        }
    }
    return 0;
}