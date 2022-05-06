//
// Created by Admin on 5/6/2022.
//
#include <stdio.h>
#include <stdlib.h>

int addPointer(int *a, int *b) {
    return *a + *b;
}

int swapIntVar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int accessIndexOfArray(int array[], int index) {
    printf("%p\n", array);
    return array[index];
//    return *(array + index);
}

int *createNewArray() {
    printf("How long do you want the array to be? Please pick an integer. > ");
    int arrayLength;
    scanf("%d", &arrayLength);
    printf("Length: %d\n", arrayLength);
    int *resultArray = calloc(arrayLength, sizeof (int));
    printf("Pointer size: %d\n", sizeof (resultArray));
    for (int i = 0; i < arrayLength; i++) {
        printf("Please pick an integer for element %d > ", i);
        scanf("%d", &resultArray[i]);

    }
    return resultArray;
}

