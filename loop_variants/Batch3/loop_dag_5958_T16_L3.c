#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int i = 0; i < N / T; i++) {
        for (int ii = 0; ii < N / T; ii++) {
            for (int j = T * i; j < T * i + T; j++) {
                for (int jj = T * ii; jj < T * ii + T; jj++) {
                    Z[jj] = Y[jj] - C[jj][jj];
                                A[jj][jj] = Y[jj] * Z[jj];
                                Y[jj] = Z[jj] * X[jj];
                                Z[jj] = Y[jj] * B[jj][jj];
                                A[jj][jj] = Y[jj] - B[jj][jj];
                                A[jj][jj] = Y[jj] - Z[jj];
                                Y[jj] = A[jj][jj] - Z[jj];
                                A[jj][jj] = Y[jj] * B[jj][jj];
                                A[jj][jj] = Y[jj] - Z[jj];
                }
            }
        }
    }
    return 0;
}