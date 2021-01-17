#include "nucleotide_count.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *count(const char *dna_strand) {
    char *buf = (char *)malloc(256);
    size_t len = strlen(dna_strand);

    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;
    for (size_t i = 0; i < len; ++i) {
        switch (dna_strand[i]) {
        case 'A':
            ++a;
            break;
        case 'C':
            ++c;
            break;
        case 'G':
            ++g;
            break;
        case 'T':
            ++t;
            break;
        default:
            buf[0] = '\0';
            return buf;
        }
    }

    sprintf(buf, "A:%d C:%d G:%d T:%d", a, c, g, t);
    return buf;
}
