#include "diamond.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char **make_diamond(const char letter) {
    int size = (letter - 'A') * 2 + 1;
    int half = (letter - 'A');

    char **ret = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) {
        ret[i] = (char *)malloc(size + 1);
        int char_pos = abs(letter - 'A' - i);
        for (int j = 0; j <= half; ++j) {
            if (j == char_pos) {
                ret[i][j] = letter - char_pos;
            } else {
                ret[i][j] = ' ';
            }
        }

        for (int j = size - 1; j >= half; --j) {
            if (size - 1 - j == char_pos) {
                ret[i][j] = letter - char_pos;
            } else {
                ret[i][j] = ' ';
            }
        }
        ret[i][size] = '\0';
    }

    return ret;
}
