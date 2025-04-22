#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 32;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    X[jj] = B[jj][ii] - A[jj][ii];
                                Z[jj] = A[jj][ii] * Y[jj];
                                X[jj] = B[jj][ii] - C[jj][ii];
                                Z[jj] = Y[jj] + A[jj][ii];
                                C[jj][ii] = Y[jj] - Z[jj];
                                Y[jj] = X[jj] - C[jj][ii];
                                Z[jj] = Z[jj] - X[jj];
                                X[jj] = Y[jj] - C[jj][ii];
                                C[jj][ii] = Y[jj] + X[jj];
                                X[jj] = A[jj][ii] + Z[jj];
                }
            }
        }
    }
    return 0;
}