#include "sum_of_multiples.h"

unsigned int sum_of_multiples(const unsigned int *multiples, const size_t number_of_multiples, const unsigned int up_to) {
    if (multiples == NULL || number_of_multiples == 0) {
        return 0;
    }

    unsigned int sum = 0;
    for (unsigned int i = 1; i < up_to; ++i) {
        for (size_t j = 0; j < number_of_multiples; ++j) {
            if (multiples[j] == 0) {
                continue;
            }

            if (i % multiples[j] == 0) {
                sum += i;
                break;
            }
        }
    }

    return sum;
}
