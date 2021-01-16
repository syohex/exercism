#include "grade_school.h"

#include <string.h>

static roster_t roster = {0};

bool add_student(char *name, uint8_t grade) {
    int pos = 0;
    for (size_t i = 0; i < roster.count; ++i) {
        if (grade == roster.students[i].grade && strcmp(name, roster.students[i].name) < 0) {
            break;
        }
        if (grade < roster.students[i].grade) {
            break;
        }

        ++pos;
    }

    for (int i = (int)roster.count; i >= pos; --i) {
        roster.students[i].name = roster.students[i - 1].name;
        roster.students[i].grade = roster.students[i - 1].grade;
    }

    roster.students[pos].name = name;
    roster.students[pos].grade = grade;
    roster.count++;
    return true;
}

roster_t get_grade(uint8_t grade) {
    roster_t ret = {0};
    size_t count = 0;
    for (size_t i = 0; i < roster.count; ++i) {
        if (roster.students[i].grade == grade) {
            ret.students[count].grade = roster.students[i].grade;
            ret.students[count].name = roster.students[i].name;
            ++count;
        }
    }

    ret.count = count;
    return ret;
}

roster_t get_roster(void) {
    return roster;
}

void clear_roster(void) {
    roster.count = 0;
}
