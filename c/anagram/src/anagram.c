#include "anagram.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

static bool strcmp_ignore_case(const char *w1, const char *w2) {
    size_t len1 = strlen(w1);
    size_t len2 = strlen(w2);
    if (len1 != len2) {
        return false;
    }

    for (size_t i = 0; i < len1; ++i) {
        if (tolower((int)w1[i]) != tolower((int)w2[i])) {
            return false;
        }
    }

    return true;
}

static bool is_anagram(const char *w1, const char *w2) {
    size_t len1 = strlen(w1);
    size_t len2 = strlen(w2);
    if (len1 != len2) {
        return false;
    }

    char t1[256] = {0};
    char t2[256] = {0};

    for (size_t i = 0; i < len1; ++i) {
        int index = tolower((int)w1[i]);
        ++t1[index];
    }

    for (size_t i = 0; i < len2; ++i) {
        int index = tolower((int)w2[i]);
        ++t2[index];
    }

    for (size_t i = 0; i < 256; ++i) {
        if (t1[i] != t2[i]) {
            return false;
        }
    }

    return true;
}

void find_anagrams(const char *subject, struct candidates *candidates) {
    for (size_t i = 0; i < candidates->count; ++i) {
        if (strcmp_ignore_case(subject, candidates->candidate[i].word)) {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
        }

        if (is_anagram(subject, candidates->candidate[i].word)) {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        } else {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }
    }
}
