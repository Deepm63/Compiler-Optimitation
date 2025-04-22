#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 128;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    Z[jj] = Y[jj] * X[jj];
                                Z[jj] = Z[jj] - X[jj];
                                X[jj] = Y[jj] + Z[jj];
                                Z[jj] = A[jj][ii] * C[jj][ii];
                                C[jj][ii] = B[jj][ii] - X[jj];
                                Y[jj] = B[jj][ii] * Z[jj];
                                X[jj] = Y[jj] * Z[jj];
                }
            }
        }
    }
    return 0;
}