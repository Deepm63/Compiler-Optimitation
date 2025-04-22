#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    A[jj][ii] = B[jj][ii] * X[jj];
                                C[jj][ii] = X[jj] - C[jj][ii];
                                C[jj][ii] = A[jj][ii] * B[jj][ii];
                                C[jj][ii] = B[jj][ii] - C[jj][ii];
                                C[jj][ii] = Y[jj] * X[jj];
                                C[jj][ii] = Z[jj] * X[jj];
                }
            }
        }
    }
    return 0;
}