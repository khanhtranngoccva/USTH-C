#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main1() {
    int array1[][4] = {
            {1, 2, 3, 4},
            {4, 5, 6, 7},
            {7, 8, 9, 10},
    };
    int rowLength = sizeof array1[0] / sizeof array1[0][0];
    int colLength = sizeof array1 / sizeof array1[0];
    long double matSum = sumOfMatrixElements(array1, colLength, rowLength);
    printf("%Lf\n", matSum);
    long double *matTranspose = matrixTranspose(array1, colLength, rowLength);
    printArray(matTranspose, rowLength, colLength);
}

