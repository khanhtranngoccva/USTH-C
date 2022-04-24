#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "string.h"

int main() {
    long double array1[][1] = {
            {2}
    };
    int rowLength = sizeof array1[0] / sizeof array1[0][0];
    int colLength = sizeof array1 / sizeof array1[0];
    printf("%Lf\n", matrixDeterminant(array1, 1));
    printArray(inverseMatrix(array1, 1), 1, 1);
}

int main1() {
    char string1[] = "oofxxx oof";
    char *string2 = filterOut(string1, 'x');
    printf("%s\n", string2);
    printf("%d\n", sizeof(string2));
    printAllIndexOfChar("hanoghooi3nejtoan3irh209aiohfoihanogeww", 'a');
}