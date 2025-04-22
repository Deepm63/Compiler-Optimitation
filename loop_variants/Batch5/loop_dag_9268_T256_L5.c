#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    B[jj][ii] = A[jj][ii] + C[jj][ii];
                                A[jj][ii] = Y[jj] * X[jj];
                                C[jj][ii] = Y[jj] + Z[jj];
                                X[jj] = Z[jj] - C[jj][ii];
                                Y[jj] = Z[jj] - C[jj][ii];
                                Y[jj] = A[jj][ii] - C[jj][ii];
                                X[jj] = A[jj][ii] + Y[jj];
                                Y[jj] = X[jj] - C[jj][ii];
                                X[jj] = Y[jj] * C[jj][ii];
                                Y[jj] = B[jj][ii] - X[jj];
                }
            }
        }
    }
    return 0;
}