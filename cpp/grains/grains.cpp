#include "grains.h"

namespace grains {

unsigned long long square(int n) {
    const auto power = [](int n) -> unsigned long long {
        if (n == 1) {
            return 1;
        }

        unsigned long long value = 2;
        for (int i = 2; i < n; ++i) {
            value *= 2ULL;
        }

        return value;
    };

    return power(n);
}

unsigned long long total() {
    unsigned long long ret = 0;
    for (int i = 1; i <= 64; ++i) {
        ret += square(i);
    }

    return ret;
}

} // namespace grains
