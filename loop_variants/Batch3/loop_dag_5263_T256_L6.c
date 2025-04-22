#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 256;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    C[i][ii] = A[i][ii] - Z[i];
                                C[i][ii] = Y[i] + Z[i];
                                C[i][ii] = Y[i] + X[i];
                                Y[i] = B[i][ii] + X[i];
                                C[i][ii] = A[i][ii] + X[i];
                                Y[i] = Y[i] - X[i];
                                X[i] = Y[i] * C[i][ii];
                                C[i][ii] = Y[i] + B[i][ii];
                                Y[i] = X[i] * C[i][ii];
                                Y[i] = X[i] + C[i][ii];
                }
            }
        }
    }
    return 0;
}