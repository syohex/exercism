#include "luhn.h"

#include <string.h>
#include <ctype.h>

bool luhn(const char *num) {
    int start = 0;
    while (isspace(num[start])) {
        ++start;
    }

    int end = (int)strlen(num) - 1;
    while (isspace(num[end])) {
        --end;
    }

    int len = end - start + 1;
    if (len <= 1) {
        return false;
    }

    int sum = 0;
    for (int i = 0, count = 0; i < len; ++i) {
        int index = end - i;
        if (num[index] == ' ') {
            continue;
        }
        if (!isdigit((int)num[index])) {
            return false;
        }

        int val = num[index] - '0';
        if (count % 2 == 1) {
            val *= 2;
            val = val >= 10 ? val - 9 : val;
        }

        sum += val;
        ++count;
    }

    return sum % 10 == 0;
}
