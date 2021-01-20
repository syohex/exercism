#include "grains.h"

#include <math.h>

uint64_t square(uint8_t index) {
    if (index == 0 || index >= 65) {
        return 0;
    }

    uint64_t ret = 1;
    return ret << (index - 1);
}

uint64_t total(void) {
    uint64_t ret = 0;
    for (uint8_t i = 1; i <= 64; ++i) {
        ret += square(i);
    }

    return ret;
}
