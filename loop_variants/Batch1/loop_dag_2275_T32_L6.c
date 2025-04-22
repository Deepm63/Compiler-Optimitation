#include <stdio.h>
#define N 1024

int main() {
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = 32;
    for (int j = 0; j < N / T; j++) {
        for (int jj = 0; jj < N / T; jj++) {
            for (int i = T * j; i < T * j + T; i++) {
                for (int ii = T * jj; ii < T * jj + T; ii++) {
                    B[i][ii] = Z[i] - X[i];
                                X[i] = A[i][ii] * Z[i];
                                X[i] = A[i][ii] - X[i];
                                X[i] = B[i][ii] - X[i];
                                A[i][ii] = X[i] - C[i][ii];
                                X[i] = A[i][ii] * X[i];
                }
            }
        }
    }
    return 0;
}