#include "rna_transcription.h"

#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna) {
    size_t len = strlen(dna);
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    for (size_t i = 0; i < len; ++i) {
        switch (dna[i]) {
        case 'C':
            ret[i] = 'G';
            break;
        case 'G':
            ret[i] = 'C';
            break;
        case 'T':
            ret[i] = 'A';
            break;
        case 'A':
            ret[i] = 'U';
            break;
        }
    }
    ret[len] = '\0';
    return ret;
}
