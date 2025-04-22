#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 8;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    Z[i] = Y[i] + C[i][ii];
                                X[i] = Z[i] + X[i];
                                Z[i] = A[i][ii] - X[i];
                                X[i] = Y[i] * C[i][ii];
                                X[i] = A[i][ii] * Z[i];
                                B[i][ii] = Z[i] * X[i];
                                X[i] = A[i][ii] + C[i][ii];
                                X[i] = B[i][ii] - Y[i];
                                X[i] = Z[i] - X[i];
                }
            }
        }
    }
    return 0;
}