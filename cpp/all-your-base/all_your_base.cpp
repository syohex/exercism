#include "all_your_base.h"

#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int input_base, const std::vector<unsigned int> &in_digits, int output_base) {
    if (input_base <= 1 || output_base <= 1) {
        throw std::invalid_argument("invalid argument");
    }

    unsigned int sum = 0;

    int i = 0;
    for (auto it = in_digits.rbegin(); it != in_digits.rend(); ++it) {
        if (*it >= input_base) {
            throw std::invalid_argument("invalid argument");
        }
        sum += *it * std::pow(input_base, i);
        ++i;
    }

    std::vector<unsigned int> ret;
    while (sum > 0) {
        ret.push_back(sum % output_base);
        sum /= output_base;
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

} // namespace all_your_base
