//
// Created by khanh on 4/22/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(const int *matrix, int colLength, int rowLength) {
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            printf("%d ", matrix[i * rowLength + j]);
        }
        printf("\n");
    }
}


long long matrixDeterminant(long *matrix, int dimension) {
    if (dimension == 0) {
        return 0;
    } else if (dimension == 1) {
        return matrix[0];
    } else if (dimension == 2) {
        return (matrix[0] * matrix[3]) - (matrix[1] * matrix[2]);
    } else {
        long long result = 0;
        int smallerDimension = dimension - 1;
        for (int i = 0; i < dimension; i++) {
            long long currentTileValue = matrix[i];
            int negative = (int) pow(-1, i);
            long long smallerMatrix[smallerDimension][smallerDimension];
            long long *smallerMatrixPointer = &smallerMatrix[0][0];
            for (int j = 1; j < dimension; j++) {
                for (int k = 0; k < dimension; k++) {
                    if (k != i) {
                        *smallerMatrixPointer = matrix[j * dimension + k];
                        smallerMatrixPointer++;
                    }
                }
            }
            result += currentTileValue * negative * matrixDeterminant(smallerMatrix, smallerDimension);;
        }
        return result;
    }
}


int main() {
    int size = 3;
    int matrix[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    int determinant = (int) matrixDeterminant(matrix, size);
    printf("%d\n", determinant);
}