#include "armstrong_numbers.h"

#include <vector>
#include <cmath>

namespace armstrong_numbers {

bool is_armstrong_number(int n) {
    std::vector<int> v;
    int orig = n;

    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    int sum = 0;
    for (int i : v) {
        sum += std::pow(i, v.size());
    }

    return sum == orig;
}

} // namespace armstrong_numbers
