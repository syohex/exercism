#include "perfect_numbers.h"

// typedef enum {
//    PERFECT_NUMBER = 1,
//    ABUNDANT_NUMBER = 2,
//    DEFICIENT_NUMBER = 3,
//    ERROR = -1
// } kind;

kind classify_number(int n) {
    if (n <= 0) {
        return ERROR;
    }

    int limit = n / 2;
    int sum = 0;
    for (int i = 1; i <= limit; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (n == sum) {
        return PERFECT_NUMBER;
    }

    return sum > n ? ABUNDANT_NUMBER : DEFICIENT_NUMBER;
}
