#include "hexadecimal.h"

#include <cmath>

namespace hexadecimal {

unsigned int convert(const std::string &input) {
    unsigned int ret = 0;

    unsigned int power = 0;
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        unsigned int num;
        if (*it >= '0' && *it <= '9') {
            num = *it - '0';
        } else if (*it >= 'a' && *it <= 'f') {
            num = *it - 'a' + 10;
        } else if (*it >= 'A' && *it <= 'F') {
            num = *it - 'A' + 10;
        } else {
            return 0;
        }

        ret += num * std::pow(16, power);
        ++power;
    }

    return ret;
}

} // namespace hexadecimal
