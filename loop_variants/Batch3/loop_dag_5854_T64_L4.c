#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 64;
    for (int j = 0; j < N / T; j++) {
        for (int i = 0; i < N / T; i++) {
            for (int ii = T * j; ii < T * j + T; ii++) {
                for (int jj = T * i; jj < T * i + T; jj++) {
                    X[ii] = Y[ii] + B[ii][jj];
                                Y[ii] = B[ii][jj] - X[ii];
                                B[ii][jj] = Y[ii] + C[ii][jj];
                                X[ii] = A[ii][jj] + C[ii][jj];
                                X[ii] = A[ii][jj] - C[ii][jj];
                                C[ii][jj] = Z[ii] - X[ii];
                                C[ii][jj] = Z[ii] + X[ii];
                }
            }
        }
    }
    return 0;
}