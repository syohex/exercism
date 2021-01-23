#include "darts.h"

#include <math.h>

// typedef struct {
//    float x;
//    float y;
//} coodinate_t;

uint8_t score(coordinate_t p) {
    double d = sqrt(p.x * p.x + p.y * p.y);
    if (d > 10) {
        return 0;
    } else if (d > 5) {
        return 1;
    } else if (d > 1) {
        return 5;
    } else {
        return 10;
    }
}
