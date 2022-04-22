#ifndef USTHC_MATRIX_H
#define USTHC_MATRIX_H
void printArray(long double *matrix, int colLength, int rowLength);
long double matrixDeterminant(long double *matrix, int dimension);
long double *mulMatrix(long double *matrix, long double scalar, int colLength, int rowLength);
long double *matrixTranspose(long double *matrix, int colLength, int rowLength);
long double *inverseMatrix(long double *matrix, int size);
long double *cofactorMatrix(long double *matrix, int size);
long double sumOfMatrixElements(long double *matrix, int colLength, int rowLength);
#endif //USTHC_MATRIX_H
