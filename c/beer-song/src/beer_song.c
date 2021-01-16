#include "beer_song.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static char *fmt = "%u bottles of beer on the wall, %u bottles of beer.\n"
                   "Take one down and pass it around, %u %s of beer on the wall.\n";
static char *one_fmt = "%u bottle of beer on the wall, %u bottle of beer.\n"
                       "Take it down and pass it around, no more bottles of beer on the wall.\n";

void recite(unsigned int start_bottles, unsigned int take_down, char *buffer) {
    char buf[256];
    bool is_lack = start_bottles < take_down;

    size_t pos = 0;
    for (unsigned int i = start_bottles, j = 0; start_bottles > 0 && j < take_down; --i, ++j) {
        if (j >= 1) {
            buffer[pos++] = '\n';
        }

        size_t len;
        if (i > 1) {
            len = sprintf(buf, fmt, i, i, i - 1, i - 1 >= 2 ? "bottles" : "bottle");
        } else {
            len = sprintf(buf, one_fmt, i, i);
        }

        memcpy(buffer + pos, buf, len);
        pos += len;
        --start_bottles;
    }

    if (is_lack) {
        if (pos > 0) {
            buffer[pos++] = '\n';
        }

        char *p = "No more bottles of beer on the wall, no more bottles of beer.\n"
                  "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        size_t len = strlen(p);
        memcpy(buffer + pos, p, len);
        pos += len;
    }

    buffer[pos] = '\0';
    printf("## %s\n", buffer);
}
