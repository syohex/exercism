#include "pangram.h"

#include <string.h>
#include <ctype.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL) {
        return false;
    }

    int table[26] = {0};
    size_t len = strlen(sentence);
    for (size_t i = 0; i < len; ++i) {
        if (!isalpha(sentence[i])) {
            continue;
        }

        int c = tolower(sentence[i]) - 'a';
        ++table[c];
    }

    for (size_t i = 0; i < 26; ++i) {
        if (table[i] == 0) {
            return false;
        }
    }

    return true;
}
