#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    Y[jj] = Y[jj] + C[jj][ii];
                                Z[jj] = Y[jj] * C[jj][ii];
                                Y[jj] = A[jj][ii] * Y[jj];
                                A[jj][ii] = Y[jj] * C[jj][ii];
                                A[jj][ii] = Z[jj] * C[jj][ii];
                                A[jj][ii] = A[jj][ii] * Z[jj];
                                C[jj][ii] = Y[jj] + Z[jj];
                                A[jj][ii] = A[jj][ii] + Y[jj];
                                Z[jj] = A[jj][ii] - C[jj][ii];
                }
            }
        }
    }
    return 0;
}