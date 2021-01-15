#include "binary.h"

#include <string.h>

int convert(const char *input) {
    size_t len = strlen(input);
    int ret = 0;
    for (size_t i = 0; i < len; ++i) {
        if (!(input[i] == '0' || input[i] == '1')) {
            return INVALID;
        }

        ret = ret * 2 + input[i] - '0';
    }

    return ret;
}
