#ifndef SERIES_H
#define SERIES_H

#define MAX_INPUT_TEXT_LENGTH (8)
#define MAX_SERIES_RESULTS (MAX_INPUT_TEXT_LENGTH)
#define MAX_SERIES_LENGTH (5)

typedef struct series_results {
    unsigned int substring_count;
    char **substring; // array of pointers of dimension substring_count
} series_results_t;

series_results_t series(char *input_text, unsigned int substring_length);

#endif
