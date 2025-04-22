#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    Y[ii] = A[ii][jj] * Z[ii];
                                Z[ii] = B[ii][jj] + A[ii][jj];
                                Z[ii] = Z[ii] + X[ii];
                                Z[ii] = Y[ii] + Z[ii];
                                Z[ii] = Z[ii] * X[ii];
                                Z[ii] = Y[ii] * X[ii];
                }
            }
        }
    }
    return 0;
}