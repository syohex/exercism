#include "luhn.h"

#include <cctype>

namespace luhn {

bool valid(const std::string &s) {
    int limit = s.size();
    if (limit <= 1) {
        return false;
    }

    int pos = limit - 1;
    int digits = 1;
    int sum = 0;
    while (pos >= 0) {
        while (pos >= 0 && std::isspace(s[pos])) {
            --pos;
        }

        if (!isdigit(s[pos])) {
            return false;
        }

        int val = s[pos] - '0';
        if (digits % 2 == 0) {
            val *= 2;
            val = val >= 10 ? val - 9 : val;
            sum += val;
        } else {
            sum += val;
        }

        ++digits;
        --pos;
    }

    return sum % 10 == 0;
}

} // namespace luhn
