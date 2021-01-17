#include "isogram.h"

#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }

    int table[26] = {0};
    size_t len = strlen(phrase);
    for (size_t i = 0; i < len; ++i) {
        if (!isalpha((int)phrase[i])) {
            continue;
        }

        int c = tolower(phrase[i]) - 'a';
        ++table[c];
    }

    for (size_t i = 0; i < 26; ++i) {
        if (table[i] >= 2) {
            return false;
        }
    }

    return true;
}
