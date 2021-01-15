#include "minesweeper.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int count_mines(int row, int col, const char **field, int rows, int cols) {
    int ret = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                if (field[r][c] == '*') {
                    ++ret;
                }
            }
        }
    }

    return ret;
}

char **annotate(const char **minefield, const size_t rows) {
    if (rows == 0) {
        return NULL;
    }

    char **ret = (char **)malloc(sizeof(char *) * rows);
    for (int i = 0; i < (int)rows; ++i) {
        int len = strlen(minefield[i]);
        ret[i] = (char *)malloc(len + 1);
        for (int j = 0; j < len; ++j) {
            switch (minefield[i][j]) {
            case '*':
                ret[i][j] = minefield[i][j];
                break;
            default: {
                int mines = count_mines(i, j, minefield, (int)rows, len);
                if (mines > 0) {
                    ret[i][j] = mines + '0';
                } else {
                    ret[i][j] = ' ';
                }
                break;
            }
            }
        }
        ret[i][len] = '\0';
    }

    return ret;
}

void free_annotation(char **annotation) {
    free(annotation);
}
