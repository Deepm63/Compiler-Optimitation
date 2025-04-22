#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 16;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    X[i] = B[i][ii] + Y[i];
                                Z[i] = B[i][ii] - X[i];
                                Z[i] = Y[i] + B[i][ii];
                                Y[i] = Y[i] - Z[i];
                                Z[i] = Y[i] * X[i];
                                Y[i] = B[i][ii] - Z[i];
                                Y[i] = Z[i] * X[i];
                                Y[i] = B[i][ii] + Z[i];
                }
            }
        }
    }
    return 0;
}