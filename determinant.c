#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(long double *matrix, int colLength, int rowLength);
long double matrixDeterminant(long double *matrix, int dimension);
long double *mulMatrix(long double *matrix, long double scalar, int colLength, int rowLength);
long double *matrixTranspose(long double *matrix, int colLength, int rowLength);
long double *inverseMatrix(long double *matrix, int size);
long double *cofactorMatrix(long double *matrix, int size);

void printArray(long double *matrix, int colLength, int rowLength) {
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            printf("%Lf ", matrix[i * rowLength + j]);
        }
        printf("\n");
    }
}
long double *mulMatrix(long double *matrix, long double scalar, int colLength, int rowLength) {
    long double *newMatrix = malloc(colLength * rowLength * sizeof (long double));
    long double *newMatrixPointer = &newMatrix[0];
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            *newMatrixPointer = matrix[i * colLength + j] * scalar;
            newMatrixPointer++;
        }
    }
    return newMatrix;
}
long double *cofactorMatrix(long double *matrix, int size) {
    int smallerSize = size-1;
    long double *resultMatrix = calloc(size * size, sizeof (long double));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            long double miniMatrix[smallerSize][smallerSize];
            long double *miniMatrixPointer = &miniMatrix[0][0];
            for (int a = 0; a < size; a++) {
                for (int b = 0; b < size; b++) {
                    if (a != i && b != j) {
                        *miniMatrixPointer = matrix[a * size + b];
                        miniMatrixPointer++;
                    }
                }
            }
            resultMatrix[i * size + j] = pow(-1, (i + j)) * matrixDeterminant(miniMatrix, smallerSize);
        }
    }
    return resultMatrix;
}
long double *inverseMatrix(long double *matrix, int size) {
    long double determinant = matrixDeterminant(matrix, size);
    long double *newCofactorMatrix = cofactorMatrix(matrix, size);
    long double *adjointMatrix = matrixTranspose(newCofactorMatrix, size, size);
    long double *resultMatrix = mulMatrix(adjointMatrix, 1 / determinant, size, size);
    return resultMatrix;
}
long double *matrixTranspose(long double *matrix, int colLength, int rowLength) {
    long double *resultMatrix = malloc(colLength * rowLength * sizeof(long double));
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            resultMatrix[j * colLength + i] = matrix[i * rowLength + j];
        }
    }
    return resultMatrix;
}
long double matrixDeterminant(long double *matrix, int dimension) {
    if (dimension == 0) {
        return 0;
    } else if (dimension == 1) {
        return matrix[0];
    } else if (dimension == 2) {
        return (matrix[0] * matrix[3]) - (matrix[1] * matrix[2]);
    } else {
        long double result = 0;
        int smallerDimension = dimension - 1;
        for (int i = 0; i < dimension; i++) {
            long double currentTileValue = matrix[i];
            int negative = (int) pow(-1, i);
            long double smallerMatrix[smallerDimension][smallerDimension];
            long double *smallerMatrixPointer = &smallerMatrix[0][0];
            for (int j = 1; j < dimension; j++) {
                for (int k = 0; k < dimension; k++) {
                    if (k != i) {
                        *smallerMatrixPointer = matrix[j * dimension + k];
                        smallerMatrixPointer++;
                    }
                }
            }
            result += currentTileValue * negative * matrixDeterminant(smallerMatrix, smallerDimension);
        }
        return result;
    }
}


int main() {
    int size = 2;
    long double matrix[][2] = {
            {1, 2},
            {4, 5},
    };
    long double *matrix2 = inverseMatrix(matrix, size);
    printArray(matrix2, size, size);
}