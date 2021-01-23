#include "space_age.h"

static float planet_days(planet_t planet) {
    switch (planet) {
    case MERCURY:
        return 365.25 * 0.2408467;
    case VENUS:
        return 365.25 * 0.61519726;
    case EARTH:
        return 365.25;
    case MARS:
        return 365.25 * 1.8808158;
    case JUPITER:
        return 365.25 * 11.862615;
    case SATURN:
        return 365.25 * 29.447498;
    case URANUS:
        return 365.25 * 84.016846;
    case NEPTUNE:
        return 365.25 * 164.79132;
    default:
        // never reach here
        return 1;
    }
}

float convert_planet_age(planet_t planet, int64_t input) {
    float days = planet_days(planet);
    float seconds = days * 24 * 3600;
    return input / seconds;
}
