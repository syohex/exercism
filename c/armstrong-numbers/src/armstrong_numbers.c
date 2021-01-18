#include "armstrong_numbers.h"

#include <math.h>

bool is_armstrong_number(int candidate) {
    int orig = candidate;
    int digits[32] = {0};
    int i = 0;

    while (candidate > 0) {
        digits[i++] = candidate % 10;
        candidate /= 10;
    }

    int sum = 0;
    for (int j = 0; j < i; ++j) {
        sum += pow(digits[j], i);
    }

    return sum == orig;
}
