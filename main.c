#include <stdio.h>
#include <stdlib.h>

int matrixSum(const int *matrix, int colLength, int rowLength) {
    int result = 0;
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            result += matrix[i * rowLength + j];
        }
    }
    return result;
}


int* matrixTranspose(const int *matrix, int colLength, int rowLength) {
    int *resultMatrix = malloc(colLength * rowLength * sizeof(int));
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            resultMatrix[j * colLength + i] = matrix[i * rowLength + j];
        }
    }
    return resultMatrix;
}

void printArray(const int *matrix, int colLength, int rowLength) {
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            printf("%d ", matrix[i * rowLength + j]);
        }
        printf("\n");
    }
}


int main1() {
    int array1[][4] = {
            {1, 2, 3, 4},
            {4, 5, 6, 7},
            {7, 8, 9, 10},
    };
    int rowLength = sizeof array1[0] / sizeof array1[0][0];
    int colLength = sizeof array1 / sizeof array1[0];
    int matSum = matrixSum(array1, colLength, rowLength);
    printf("%d\n", matSum);
    int *matTranspose = matrixTranspose(array1, colLength, rowLength);
    printArray(matTranspose, rowLength, colLength);
}

