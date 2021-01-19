#include "triangle.h"

static bool is_triangle(triangle_t t) {
    return t.a + t.b > t.c && t.b + t.c > t.a && t.c + t.a > t.b;
}

bool is_equilateral(triangle_t t) {
    if (!is_triangle(t)) {
        return false;
    }

    return t.a == t.b && t.b == t.c;
}

bool is_isosceles(triangle_t t) {
    if (!is_triangle(t)) {
        return false;
    }

    return t.a == t.b || t.b == t.c || t.a == t.c;
}

bool is_scalene(triangle_t t) {
    if (is_equilateral(t) || is_isosceles(t)) {
        return false;
    }

    return is_triangle(t);
}
