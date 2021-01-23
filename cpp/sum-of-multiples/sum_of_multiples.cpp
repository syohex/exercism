#include "sum_of_multiples.h"

namespace sum_of_multiples {

int to(std::initializer_list<int> divs, int limit) {
    if (divs.size() == 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 1; i < limit; ++i) {
        for (int div : divs) {
            if (div == 0) {
                continue;
            }

            if (i % div == 0) {
                sum += i;
                break;
            }
        }
    }

    return sum;
}

} // namespace sum_of_multiples
