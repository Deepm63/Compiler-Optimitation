#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 128;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    B[i][ii] = Y[i] + Z[i];
                                Z[i] = A[i][ii] * X[i];
                                Y[i] = A[i][ii] - C[i][ii];
                                B[i][ii] = B[i][ii] * A[i][ii];
                                X[i] = A[i][ii] + B[i][ii];
                                B[i][ii] = A[i][ii] * X[i];
                                A[i][ii] = B[i][ii] + X[i];
                                B[i][ii] = A[i][ii] - Y[i];
                                A[i][ii] = B[i][ii] * X[i];
                                B[i][ii] = A[i][ii] - Z[i];
                }
            }
        }
    }
    return 0;
}