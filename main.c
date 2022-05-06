#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "string.h"
#include "pointer.h"



void printIntArray(int *matrix, int colLength, int rowLength) {
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            printf("%d ", matrix[i * rowLength + j]);
        }
        printf("\n");
    }
}

int main() {
    int integer = 1;
    int *p = &integer;
    int **q = &p;
    int mainArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", **q);
    int *arrayOfPointers[10];
    for (int i = 0; i < sizeof (mainArray) / sizeof (int); i++) {
        arrayOfPointers[i] = &mainArray[i];
    }
    for (int i = 0; i < sizeof (mainArray) / sizeof (int); i++) {
        printf("%p\n", arrayOfPointers[i]);
    }
}

int main2() {
    long double array1[][1] = {
            {2}
    };
    int rowLength = sizeof array1[0] / sizeof array1[0][0];
    int colLength = sizeof array1 / sizeof array1[0];
    printf("%Lf\n", matrixDeterminant(array1, rowLength));
    printArray(inverseMatrix(array1, rowLength), colLength, rowLength);
}

int main3() {
    char string1[] = "oofxxx oof";
    char *string2 = filterOut(string1, 'x');
    printf("%s\n", string2);
    printf("%d\n", sizeof(string2));
    printAllIndexOfChar("hanoghooi3nejtoan3irh209aiohfoihanogeww", 'a');
}