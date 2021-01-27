#include "sieve.h"

#include <stdlib.h>
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    char *table = (char *)malloc(limit + 1);
    memset(table, 1, limit + 1);

    table[0] = 0;
    table[1] = 0;
    for (size_t i = 2; i <= limit; ++i) {
        if (table[i] == 0) {
            continue;
        }

        for (size_t j = i + i; j <= limit; j += i) {
            table[j] = 0;
        }
    }

    uint32_t pos = 0;
    for (uint32_t i = 2; i <= limit; ++i) {
        if (table[i] == 1) {
            primes[pos++] = i;
            if (pos >= max_primes) {
                break;
            }
        }
    }

    free(table);
    return pos;
}
