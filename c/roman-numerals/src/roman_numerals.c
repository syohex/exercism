#include "roman_numerals.h"

#include <stdlib.h>

static void set(char *p, size_t *pos, int value, char high, char mid, char low) {
    switch (value) {
    case 1:
    case 2:
    case 3:
        for (int i = 0; i < value; ++i) {
            p[(*pos)++] = low;
        }
        break;
    case 4:
        p[(*pos)++] = low;
        p[(*pos)++] = mid;
        break;
    case 5:
        p[(*pos)++] = mid;
        break;
    case 6:
    case 7:
    case 8:
        p[(*pos)++] = mid;
        for (int i = 0; i < value - 5; ++i) {
            p[(*pos)++] = low;
        }
        break;
    case 9:
        p[(*pos)++] = low;
        p[(*pos)++] = high;
        break;
    default:
        break;
    }
}

char *to_roman_numeral(unsigned int number) {
    char *ret = (char *)malloc(1024);
    size_t pos = 0;

    while (number >= 1000) {
        ret[pos++] = 'M';
        number -= 1000;
    }

    set(ret, &pos, number / 100, 'M', 'D', 'C');
    number %= 100;
    set(ret, &pos, number / 10, 'C', 'L', 'X');
    number %= 10;
    set(ret, &pos, number, 'X', 'V', 'I');

    ret[pos] = '\0';
    return ret;
}
