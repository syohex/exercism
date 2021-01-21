#include "nth_prime.h"

#include <math.h>
#include <stdbool.h>

static bool is_prime(uint32_t n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }

    uint32_t limit = sqrt(n);
    for (uint32_t i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

uint32_t nth(uint32_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }

    uint32_t i = 3;
    uint32_t count = 1;
    while (true) {
        if (is_prime(i)) {
            ++count;
            if (count == n) {
                break;
            }
        }

        i += 2;
    }

    return i;
}
