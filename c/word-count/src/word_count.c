#include "word_count.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static bool strcmp_ignore_case(const char *w1, const char *w2, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        if (tolower(w1[i]) != tolower(w2[i])) {
            return false;
        }
    }

    return true;
}

int word_count(const char *input_text, word_count_word_t *words) {
    size_t len = strlen(input_text);
    size_t pos = 0;
    int count = 0;
    size_t start = 0;
    while (pos < len) {
        while (pos < len && !isalnum(input_text[pos])) {
            ++pos;
        }

        start = pos;

        while (pos < len && (isalnum(input_text[pos]) || input_text[pos] == '\'')) {
            ++pos;
        }

        size_t end = pos;
        while (end > 0 && input_text[end - 1] == '\'') {
            --end;
        }

        size_t word_len = end - start;
        if (word_len == 0) {
            continue;
        }

        if (word_len > MAX_WORD_LENGTH) {
            return EXCESSIVE_LENGTH_WORD;
        }

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp_ignore_case(words[i].text, input_text + start, word_len)) {
                ++words[i].count;
                found = true;
                break;
            }
        }

        if (!found) {
            if (count >= MAX_WORDS) {
                return EXCESSIVE_NUMBER_OF_WORDS;
            }

            for (size_t i = 0; i < word_len; ++i) {
                words[count].text[i] = tolower(input_text[start + i]);
            }
            words[count].text[word_len] = '\0';
            words[count].count = 1;
            ++count;
        }
    }

    return count;
}
