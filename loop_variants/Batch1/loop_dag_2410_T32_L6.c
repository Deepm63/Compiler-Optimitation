#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 32;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    Z[i] = A[i][ii] + Z[i];
                                Z[i] = B[i][ii] - C[i][ii];
                                Z[i] = B[i][ii] - Y[i];
                                B[i][ii] = Z[i] - X[i];
                                Z[i] = Y[i] + C[i][ii];
                                B[i][ii] = Y[i] + X[i];
                                Z[i] = B[i][ii] * Z[i];
                }
            }
        }
    }
    return 0;
}