#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 8;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int jj = T * j; jj < T * j + T; jj++) {
                for (int ii = T * i; ii < T * i + T; ii++) {
                    Y[jj] = Y[jj] + A[jj][ii];
                                A[jj][ii] = Y[jj] - X[jj];
                                Y[jj] = Y[jj] + Z[jj];
                                Y[jj] = A[jj][ii] + X[jj];
                                Y[jj] = A[jj][ii] * Y[jj];
                                A[jj][ii] = Y[jj] + X[jj];
                                Y[jj] = Y[jj] + Z[jj];
                }
            }
        }
    }
    return 0;
}