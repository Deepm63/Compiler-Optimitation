#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int ii = T * j; ii < T * j + T; ii++) {
                for (int jj = T * i; jj < T * i + T; jj++) {
                    B[ii][jj] = Z[ii] + C[ii][jj];
                                C[ii][jj] = Z[ii] - X[ii];
                                B[ii][jj] = Z[ii] * X[ii];
                                Z[ii] = B[ii][jj] + A[ii][jj];
                                C[ii][jj] = Z[ii] + X[ii];
                                X[ii] = A[ii][jj] - C[ii][jj];
                                X[ii] = B[ii][jj] * Z[ii];
                }
            }
        }
    }
    return 0;
}