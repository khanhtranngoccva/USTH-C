#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *reverseString(char originalString[]) {
    int realLength = (int) strlen(originalString) + 1;
    printf("%L\n", realLength);
    char *newString = calloc(realLength, sizeof(char));
    newString[realLength - 1] = '\0';
    for (int i = realLength - 2; i >= 0; i--) {
        newString[realLength - 2 - i] = originalString[i];
    }
    printf("%s\n", newString);
    return newString;
}


char *filterOut(char originalString[], char leaveOut) {
    char *newHeapString = calloc((int) strlen(originalString) + 1, sizeof(char));
    for (int i = 0; i < strlen(originalString); i++) {
        char newChar = originalString[i];
        if (newChar != leaveOut) {
            strncat(newHeapString, &newChar, 1);
        }
    }
    return newHeapString;
}

void printAllIndexOfChar(char originalString[], char findMe) {
    for (int i = 0; i < strlen(originalString); i++) {
        char curChar = originalString[i];
        if (curChar == findMe) {
            printf("Character %c found at index %i\n", curChar, i);
        }
    }
}