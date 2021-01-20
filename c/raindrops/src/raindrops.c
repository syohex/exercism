#include "raindrops.h"

#include <stdio.h>
#include <string.h>

char *convert(char result[], int drops) {
    size_t pos = 0;
    if (drops % 3 == 0) {
        strcpy(result + pos, "Pling");
        pos += strlen("Pling");
    }
    if (drops % 5 == 0) {
        strcpy(result + pos, "Plang");
        pos += strlen("Plang");
    }
    if (drops % 7 == 0) {
        strcpy(result + pos, "Plong");
        pos += strlen("Plong");
    }

    if (pos == 0) {
        sprintf(result, "%d", drops);
        return result;
    }

    return &result[0];
}
