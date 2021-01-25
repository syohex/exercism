#include "acronym.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {
    if (phrase == NULL) {
        return NULL;
    }

    size_t len = strlen(phrase);
    if (len == 0) {
        return NULL;
    }

    char *ret = (char *)malloc(len);
    size_t pos = 0;
    for (size_t i = 0; i < len; ++i) {
        if (i == 0 && isalpha((int)phrase[i])) {
            ret[pos++] = toupper((int)phrase[i]);
        } else if (!isalpha((int)phrase[i - 1]) && isalpha((int)phrase[i])) {
            if (phrase[i - 1] != '\'' || !(i >= 2 && isalpha((int)phrase[i - 2]))) {
                ret[pos++] = toupper((int)phrase[i]);
            }
        }
    }

    ret[pos] = '\0';
    return ret;
}
