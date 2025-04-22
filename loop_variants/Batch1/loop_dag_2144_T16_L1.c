#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    C[ii][jj] = Y[ii] * Z[ii];
                                Z[ii] = Z[ii] + X[ii];
                                X[ii] = Z[ii] * C[ii][jj];
                                X[ii] = B[ii][jj] + Z[ii];
                                X[ii] = B[ii][jj] + C[ii][jj];
                                Z[ii] = X[ii] + C[ii][jj];
                                C[ii][jj] = Z[ii] * X[ii];
                                C[ii][jj] = B[ii][jj] - X[ii];
                }
            }
        }
    }
    return 0;
}