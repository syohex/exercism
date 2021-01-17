#include "meetup.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

enum Type {
    kTeenth,
    kFirst,
    kSecond,
    kThird,
    kFourth,
    kLast,
};

static int get_weekday(unsigned int year, unsigned int month, unsigned int day) {
    // zeller's congruence
    if (month <= 2) {
        year -= 1;
        month += 12;
    }

    return (year + (year / 4) - (year / 100) + (year / 400) + (13 * month + 8) / 5 + day) % 7;
}

static enum Type week_to_type(const char *week) {
    if (strcmp(week, "teenth") == 0) {
        return kTeenth;
    } else if (strcmp(week, "first") == 0) {
        return kFirst;
    } else if (strcmp(week, "second") == 0) {
        return kSecond;
    } else if (strcmp(week, "third") == 0) {
        return kThird;
    } else if (strcmp(week, "fourth") == 0) {
        return kFourth;
    } else if (strcmp(week, "last") == 0) {
        return kLast;
    } else {
        assert(!"invalid input");
        return kLast;
    }
}

static int day_of_week_str_to_int(const char *day_of_week) {
    if (strcmp(day_of_week, "Sunday") == 0) {
        return 0;
    } else if (strcmp(day_of_week, "Monday") == 0) {
        return 1;
    } else if (strcmp(day_of_week, "Tuesday") == 0) {
        return 2;
    } else if (strcmp(day_of_week, "Wednesday") == 0) {
        return 3;
    } else if (strcmp(day_of_week, "Thursday") == 0) {
        return 4;
    } else if (strcmp(day_of_week, "Friday") == 0) {
        return 5;
    } else if (strcmp(day_of_week, "Saturday") == 0) {
        return 6;
    } else {
        assert(!"invalid week day");
        return -1;
    }
}

static int find_teenth_day(unsigned int year, unsigned int month, int weekday) {
    int w = get_weekday(year, month, 1);
    int d = 1;
    while (1) {
        if (w == weekday) {
            if (d >= 13) {
                return d;
            }
        }

        ++d;
        w = (w + 1) % 7;
    }
}

static int find_nth_day(unsigned int year, unsigned int month, int count, int weekday) {
    int w = get_weekday(year, month, 1);
    int d = 1;
    int c = 1;
    while (1) {
        if (w == weekday) {
            if (c == count) {
                return d;
            }

            ++c;
        }

        ++d;
        w = (w + 1) % 7;
    }
}

static int month_days(unsigned int year, unsigned int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return days[month - 1];
    }

    if (year % 4 != 0) {
        return 28;
    }

    if (year % 100 == 0) {
        return year % 400 == 0 ? 29 : 28;
    }

    return 29;
}

static int find_last_day(unsigned int year, unsigned int month, int weekday) {
    int w = get_weekday(year, month, 1);
    int limit = month_days(year, month);
    int ret = 0;
    for (int i = 1; i <= limit; ++i) {
        if (w == weekday) {
            ret = i;
        }

        w = (w + 1) % 7;
    }

    return ret;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week) {
    int weekday = day_of_week_str_to_int(day_of_week);
    enum Type type = week_to_type(week);
    switch (type) {
    case kTeenth:
        return find_teenth_day(year, month, weekday);
    case kFirst:
        return find_nth_day(year, month, 1, weekday);
    case kSecond:
        return find_nth_day(year, month, 2, weekday);
    case kThird:
        return find_nth_day(year, month, 3, weekday);
    case kFourth:
        return find_nth_day(year, month, 4, weekday);
    case kLast:
        return find_last_day(year, month, weekday);
    }

    return 0;
}
