#include "run_length_encoding.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *encode(const char *text) {
    if (text == NULL) {
        return NULL;
    }

    size_t len = strlen(text);
    char *ret = (char *)malloc(len + 1);
    if (len == 0) {
        ret[len] = '\0';
        return ret;
    }

    size_t pos = 0;
    size_t p = 0;
    while (p < len) {
        char c = text[p];
        int count = 0;
        while (p < len && text[p] == c) {
            ++count;
            ++p;
        }

        if (count > 1) {
            int tmp[64];
            int digits = 0;
            while (count > 0) {
                tmp[digits++] = count % 10;
                count /= 10;
            }

            for (int i = 1; i <= digits; ++i) {
                ret[pos++] = tmp[digits - i] + '0';
            }
        }

        ret[pos++] = c;
    }

    ret[pos] = '\0';
    return ret;
}

char *decode(const char *data) {
    if (data == NULL) {
        return NULL;
    }

    size_t len = strlen(data);
    char *ret = (char *)malloc(4096);
    if (len == 0) {
        ret[len] = '\0';
        return ret;
    }

    size_t pos = 0;
    size_t p = 0;
    while (p < len) {
        int count = 0;
        while (isdigit(data[p])) {
            count = 10 * count + data[p++] - '0';
        }

        char c = data[p++];
        count = count == 0 ? 1 : count;
        for (int i = 0; i < count; ++i) {
            ret[pos++] = c;
        }
    }

    ret[pos] = '\0';
    return ret;
}
