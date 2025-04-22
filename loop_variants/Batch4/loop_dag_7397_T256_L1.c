#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    B[ii][jj] = Z[ii] * X[ii];
                                Y[ii] = A[ii][jj] * C[ii][jj];
                                X[ii] = A[ii][jj] - B[ii][jj];
                                Y[ii] = B[ii][jj] + C[ii][jj];
                                X[ii] = Y[ii] - A[ii][jj];
                                X[ii] = B[ii][jj] * Z[ii];
                                X[ii] = B[ii][jj] - Y[ii];
                }
            }
        }
    }
    return 0;
}