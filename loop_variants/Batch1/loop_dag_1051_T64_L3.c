#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int i = 0; i < N / T; i++) {
        for (int ii = 0; ii < N / T; ii++) {
            for (int j = T * i; j < T * i + T; j++) {
                for (int jj = T * ii; jj < T * ii + T; jj++) {
                    X[jj] = B[jj][jj] - Z[jj];
                                X[jj] = A[jj][jj] * Z[jj];
                                Y[jj] = B[jj][jj] + Z[jj];
                                Y[jj] = A[jj][jj] + B[jj][jj];
                                Y[jj] = Z[jj] - X[jj];
                                Z[jj] = Y[jj] * X[jj];
                                Y[jj] = A[jj][jj] * C[jj][jj];
                                X[jj] = Y[jj] - B[jj][jj];
                                Y[jj] = Y[jj] - C[jj][jj];
                }
            }
        }
    }
    return 0;
}