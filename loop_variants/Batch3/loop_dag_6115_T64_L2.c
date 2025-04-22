#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int jj = T * i; jj < T * i + T; jj++) {
                for (int ii = T * j; ii < T * j + T; ii++) {
                    B[jj][ii] = Y[jj] - Z[jj];
                                Z[jj] = Y[jj] - B[jj][ii];
                                Z[jj] = Y[jj] - Z[jj];
                                B[jj][ii] = B[jj][ii] - C[jj][ii];
                                Z[jj] = B[jj][ii] - C[jj][ii];
                                A[jj][ii] = B[jj][ii] - Z[jj];
                                Z[jj] = B[jj][ii] + X[jj];
                                Z[jj] = A[jj][ii] * Z[jj];
                                Z[jj] = A[jj][ii] - Z[jj];
                                Z[jj] = Z[jj] - X[jj];
                }
            }
        }
    }
    return 0;
}