#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int i = 0; i < N / T; i++) {
        for (int ii = 0; ii < N / T; ii++) {
            for (int j = T * i; j < T * i + T; j++) {
                for (int jj = T * ii; jj < T * ii + T; jj++) {
                    Z[jj] = A[jj][jj] + X[jj];
                                X[jj] = A[jj][jj] * C[jj][jj];
                                A[jj][jj] = Z[jj] - X[jj];
                                X[jj] = B[jj][jj] + Z[jj];
                                Z[jj] = B[jj][jj] + X[jj];
                                X[jj] = Y[jj] - C[jj][jj];
                                X[jj] = B[jj][jj] * X[jj];
                                X[jj] = A[jj][jj] - X[jj];
                }
            }
        }
    }
    return 0;
}