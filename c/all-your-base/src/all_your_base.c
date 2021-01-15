#include "all_your_base.h"

#include <math.h>
#include <stdio.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length) {
    if (input_base <= 1 || output_base <= 1) {
        goto invalid;
    }

    int sum = 0;
    for (size_t i = 0; i < input_length; ++i) {
        if (digits[i] < 0 || digits[i] >= input_base) {
            goto invalid;
        }

        sum += digits[i] * (int)pow(input_base, input_length - i - 1);
    }

    size_t pos = 0;
    while (sum > 0) {
        digits[pos++] = sum % output_base;
        sum /= output_base;
    }

    for (size_t i = 0; i < pos / 2; ++i) {
        int tmp = digits[i];
        digits[i] = digits[pos - i - 1];
        digits[pos - i - 1] = tmp;
    }

    return pos;

invalid:
    return 0;
}
