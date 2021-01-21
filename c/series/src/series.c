#include "series.h"

#include <string.h>
#include <stdlib.h>

//#define MAX_INPUT_TEXT_LENGTH (8)
//#define MAX_SERIES_RESULTS (MAX_INPUT_TEXT_LENGTH)
//#define MAX_SERIES_LENGTH (5)
//
// typedef struct series_results {
//   unsigned int substring_count;
//   char **substring;            // array of pointers of dimension substring_count
//} series_results_t;

series_results_t series(char *input_text, unsigned int substring_length) {
    series_results_t ret = {0, NULL};
    size_t len = strlen(input_text);
    if (substring_length == 0 || substring_length > len) {
        return ret;
    }

    ret.substring_count = len - substring_length + 1;
    ret.substring = (char **)malloc(sizeof(char *) * ret.substring_count);
    for (unsigned int i = 0; i <= len - substring_length; ++i) {
        ret.substring[i] = (char *)malloc(substring_length + 1);
        strncpy(ret.substring[i], input_text + i, substring_length);
        ret.substring[i][substring_length] = '\0';
    }

    return ret;
}
