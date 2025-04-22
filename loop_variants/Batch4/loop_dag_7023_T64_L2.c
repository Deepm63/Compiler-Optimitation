#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int jj = T * i; jj < T * i + T; jj++) {
                for (int ii = T * j; ii < T * j + T; ii++) {
                    C[jj][ii] = B[jj][ii] + X[jj];
                                X[jj] = A[jj][ii] + B[jj][ii];
                                A[jj][ii] = Y[jj] + C[jj][ii];
                                C[jj][ii] = A[jj][ii] + X[jj];
                                C[jj][ii] = A[jj][ii] - X[jj];
                                X[jj] = A[jj][ii] * Z[jj];
                                A[jj][ii] = B[jj][ii] * Z[jj];
                                Z[jj] = A[jj][ii] + C[jj][ii];
                                Z[jj] = X[jj] * C[jj][ii];
                                X[jj] = A[jj][ii] - Z[jj];
                }
            }
        }
    }
    return 0;
}