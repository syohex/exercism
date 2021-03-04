#include "etl.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static int char_point(char c) {
    switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'L':
    case 'N':
    case 'R':
    case 'S':
    case 'T':
        return 1;
    case 'D':
    case 'G':
        return 2;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
        return 3;
    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
        return 4;
    case 'K':
        return 5;
    case 'J':
    case 'X':
        return 8;
    case 'Q':
    case 'Z':
        return 10;
    default:
        // never reach here
        printf("## invalid char=%d\n", c);
        assert(0);
        return -1;
    }
}

static int compare(const void *a, const void *b) {
    new_map n1 = *(new_map *)a;
    new_map n2 = *(new_map *)b;

    if (n1.key == n2.key) {
        return 0;
    }

    if (n1.key > n2.key) {
        return 1;
    }

    return -1;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output) {

    int count = 0;
    for (size_t i = 0; i < input_len; ++i) {
        const legacy_map *p = input + i;
        count += strlen(p->keys);
    }

    new_map *q = (new_map *)malloc(sizeof(new_map) * count);

    count = 0;
    for (size_t i = 0; i < input_len; ++i) {
        const legacy_map *p = input + i;
        size_t len = strlen(p->keys);
        for (size_t j = 0; j < len; ++j) {
            q[count].key = tolower((int)p->keys[j]);
            q[count].value = char_point(p->keys[j]);
            ++count;
        }
    }

    qsort(q, count, sizeof(new_map), compare);

    *output = q;
    return count;
}
