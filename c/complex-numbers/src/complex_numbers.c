#include "complex_numbers.h"

#include <math.h>

complex_t c_add(complex_t a, complex_t b) {
    return (complex_t){a.real + b.real, a.imag + b.imag};
}

complex_t c_sub(complex_t a, complex_t b) {
    return (complex_t){a.real - b.real, a.imag - b.imag};
}

complex_t c_mul(complex_t a, complex_t b) {
    double real = (a.real * b.real) - (a.imag * b.imag);
    double img = (a.imag * b.real) + (a.real * b.imag);
    return (complex_t){real, img};
}

complex_t c_div(complex_t a, complex_t b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    double real = ((a.real * b.real) + (a.imag * b.imag)) / denominator;
    double img = ((a.imag * b.real) - (a.real * b.imag)) / denominator;

    return (complex_t){real, img};
}

double c_abs(complex_t x) {
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x) {
    return (complex_t){x.real, -1 * x.imag};
}

double c_real(complex_t x) {
    return x.real;
}

double c_imag(complex_t x) {
    return x.imag;
}

complex_t c_exp(complex_t x) {
    double real = exp(x.real) * cos(x.imag);
    double img = exp(x.real) * sin(x.imag);
    return (complex_t){real, img};
}
