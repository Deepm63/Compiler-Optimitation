#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 128;
    for (int i = 0; i < N / T; i++) {
        for (int ii = 0; ii < N / T; ii++) {
            for (int j = T * i; j < T * i + T; j++) {
                for (int jj = T * ii; jj < T * ii + T; jj++) {
                    A[jj][jj] = B[jj][jj] * X[jj];
                                X[jj] = B[jj][jj] + Y[jj];
                                X[jj] = X[jj] + C[jj][jj];
                                A[jj][jj] = B[jj][jj] * X[jj];
                                C[jj][jj] = A[jj][jj] * X[jj];
                                A[jj][jj] = B[jj][jj] + X[jj];
                                X[jj] = A[jj][jj] * X[jj];
                                X[jj] = Y[jj] - X[jj];
                                X[jj] = Z[jj] - X[jj];
                                X[jj] = A[jj][jj] - X[jj];
                }
            }
        }
    }
    return 0;
}