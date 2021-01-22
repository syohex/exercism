#include "pascals_triangle.h"

#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        free(triangle[i]);
    }

    free(triangle);
}

uint8_t **create_triangle(size_t rows) {
    if (rows == 0) {
        uint8_t **ret = (uint8_t **)malloc(sizeof(char *) * 1);
        ret[0] = (uint8_t *)malloc(sizeof(uint8_t) * 1);
        ret[0][0] = 0;
        return ret;
    }

    uint8_t **ret = (uint8_t **)malloc(sizeof(char *) * rows);
    for (size_t i = 0; i < rows; ++i) {
        ret[i] = (uint8_t *)malloc(sizeof(uint8_t) * (i + 1));
        for (size_t j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                ret[i][j] = 1;
            } else {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
    }

    return ret;
}
