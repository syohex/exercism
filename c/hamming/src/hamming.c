#include "hamming.h"

#include <string.h>

int compute(const char *lhs, const char *rhs) {
    size_t len1 = strlen(lhs);
    size_t len2 = strlen(rhs);
    if (len1 != len2) {
        return -1;
    }

    int count = 0;
    for (size_t i = 0; i < len1; ++i) {
        if (lhs[i] != rhs[i]) {
            ++count;
        }
    }

    return count;
}
