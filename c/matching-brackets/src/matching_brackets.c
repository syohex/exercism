#include "matching_brackets.h"

#include <stdlib.h>
#include <string.h>

bool is_paired(const char *input) {
    size_t len = strlen(input);
    char *stack = (char *)malloc(len);
    size_t pos = 0;
    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
        case '(':
        case '{':
        case '[':
            stack[pos++] = input[i];
            break;
        case ')':
            if (pos == 0 || stack[pos - 1] != '(') {
                free(stack);
                return false;
            }
            --pos;
            break;
        case '}':
            if (pos == 0 || stack[pos - 1] != '{') {
                free(stack);
                return false;
            }
            --pos;
            break;
        case ']':
            if (pos == 0 || stack[pos - 1] != '[') {
                free(stack);
                return false;
            }

            --pos;
            break;
        }
    }

    free(stack);
    return pos == 0;
}
