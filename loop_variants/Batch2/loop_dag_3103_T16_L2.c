#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int jj = T * i; jj < T * i + T; jj++) {
                for (int ii = T * j; ii < T * j + T; ii++) {
                    C[jj][ii] = B[jj][ii] * Z[jj];
                                B[jj][ii] = A[jj][ii] + X[jj];
                                Y[jj] = A[jj][ii] - C[jj][ii];
                                C[jj][ii] = Y[jj] - Z[jj];
                                B[jj][ii] = Y[jj] * Z[jj];
                                Z[jj] = Y[jj] + B[jj][ii];
                                Z[jj] = X[jj] + C[jj][ii];
                }
            }
        }
    }
    return 0;
}