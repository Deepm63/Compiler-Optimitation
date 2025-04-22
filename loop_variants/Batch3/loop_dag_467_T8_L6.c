#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 8;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    Z[i] = A[i][ii] - C[i][ii];
                                Y[i] = Z[i] + X[i];
                                Z[i] = Y[i] - A[i][ii];
                                A[i][ii] = Y[i] + Z[i];
                                A[i][ii] = A[i][ii] * Y[i];
                                Z[i] = A[i][ii] * Y[i];
                                Y[i] = A[i][ii] - Z[i];
                }
            }
        }
    }
    return 0;
}