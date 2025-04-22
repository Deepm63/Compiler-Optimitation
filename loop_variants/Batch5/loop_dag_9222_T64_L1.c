#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int i = 0; i < N / T; i++) {
        for (int j = 0; j < N / T; j++) {
            for (int ii = T * i; ii < T * i + T; ii++) {
                for (int jj = T * j; jj < T * j + T; jj++) {
                    X[ii] = Y[ii] - A[ii][jj];
                                A[ii][jj] = X[ii] + C[ii][jj];
                                Y[ii] = B[ii][jj] * X[ii];
                                A[ii][jj] = X[ii] * C[ii][jj];
                                X[ii] = A[ii][jj] - X[ii];
                                X[ii] = Y[ii] - A[ii][jj];
                                X[ii] = Y[ii] - X[ii];
                                A[ii][jj] = Z[ii] * X[ii];
                }
            }
        }
    }
    return 0;
}