//
// Created by khanh on 4/21/2022.
//

#include <stdio.h>
#include "header.h"

int absolute_number(number) {
    return number >= 0 ? number : -number;
}

_Bool is_even(number) {
    return number % 2 == 0;
}

int m() {
    int result;
    int input;
    printf("Enter an integer (positive or negative number)\n");
    scanf("%d", &input);
    result = absolute_number(input);
    printf("The absolute value of %d is %d\n", input, result);
    if (divisible_by_number(input, 3)) {
        printf("Divisible by 3");
    } else {
        printf("Not divisible by 3");
    }
    return 0;
}


double average(x, y, z, t) {
    return (x + y + z + t) / 4;
}
