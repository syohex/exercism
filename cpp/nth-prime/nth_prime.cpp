#include "nth_prime.h"

#include <cmath>
#include <cstdio>
#include <stdexcept>

namespace nth_prime {

namespace {

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }

    if (n % 2 == 0) {
        return false;
    }

    int limit = std::sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

} // namespace

int nth(int n) {
    if (n <= 0) {
        throw std::domain_error("invalid input");
    }
    if (n == 1) {
        return 2;
    }

    int count = 1;
    int i = 3;
    while (true) {
        if (is_prime(i)) {
            ++count;
            if (count == n) {
                return i;
            }
        }

        i += 2;
    }
}

} // namespace nth_prime
