#include "atbash_cipher.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char *atbash_encode(const char *input) {
    size_t len = strlen(input);
    char *ret = (char *)malloc(len + 1);
    size_t j = 0;
    size_t pos = 0;
    for (size_t i = 0; i < len; ++i) {
        if (!isalnum((int)input[i])) {
            continue;
        }

        ++pos;

        if (isalpha((int)input[i])) {
            ret[j++] = 'a' + ('z' - tolower(input[i]));
        } else {
            ret[j++] = input[i];
        }

        if (pos % 5 == 0) {
            ret[j++] = ' ';
        }
    }

    if (ret[j - 1] == ' ') {
        --j;
    }

    ret[j] = '\0';

    return ret;
}

char *atbash_decode(const char *input) {
    size_t len = strlen(input);
    char *ret = (char *)malloc(len);

    size_t pos = 0;
    for (size_t i = 0; i < len; ++i) {
        if (input[i] == ' ') {
            continue;
        }

        if (isalpha((int)input[i])) {
            ret[pos++] = 'a' + ('z' - input[i]);
        } else {
            ret[pos++] = input[i];
        }
    }
    ret[pos] = '\0';

    return ret;
}
