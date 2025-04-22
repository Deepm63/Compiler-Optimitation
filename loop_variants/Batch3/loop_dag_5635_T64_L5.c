#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    A[jj][ii] = Y[jj] - Z[jj];
                                X[jj] = A[jj][ii] + C[jj][ii];
                                X[jj] = B[jj][ii] * Z[jj];
                                A[jj][ii] = X[jj] * C[jj][ii];
                                B[jj][ii] = A[jj][ii] - Z[jj];
                                B[jj][ii] = Z[jj] + X[jj];
                                Z[jj] = A[jj][ii] - B[jj][ii];
                }
            }
        }
    }
    return 0;
}