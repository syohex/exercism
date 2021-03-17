#include "triangle.h"

#include <stdexcept>

namespace triangle {

flavor kind(double a, double b, double c) {
    if (!((a + b > c) && (b + c > a) && (c + a > b))) {
        throw std::domain_error("not triangle");
    }

    if (a == b && b == c) {
        return flavor::equilateral;
    }
    if (a == b || b == c || a == c) {
        return flavor::isosceles;
    }

    return flavor::scalene;
}

} // namespace triangle
