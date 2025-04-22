#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 128;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    Y[jj] = A[jj][ii] * C[jj][ii];
                                Z[jj] = Y[jj] + X[jj];
                                X[jj] = Y[jj] - Z[jj];
                                Z[jj] = Z[jj] + C[jj][ii];
                                X[jj] = Z[jj] * C[jj][ii];
                                Z[jj] = A[jj][ii] * X[jj];
                                X[jj] = A[jj][ii] + X[jj];
                                Z[jj] = Z[jj] - X[jj];
                                X[jj] = Y[jj] - A[jj][ii];
                }
            }
        }
    }
    return 0;
}