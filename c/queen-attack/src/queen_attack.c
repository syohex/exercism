#include "queen_attack.h"

#include <stdbool.h>
#include <stdlib.h>

static bool is_valid_position(position_t *p) {
    return p->row <= 7 && p->column <= 7;
}

static bool is_same_position(position_t *p1, position_t *p2) {
    return p1->row == p2->row && p1->column == p2->column;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (!(is_valid_position(&queen_1) && is_valid_position(&queen_2))) {
        return INVALID_POSITION;
    }

    if (is_same_position(&queen_1, &queen_2)) {
        return INVALID_POSITION;
    }

    if ((queen_1.row == queen_2.row) || (queen_1.column == queen_2.column)) {
        return CAN_ATTACK;
    }

    int x_diff = abs(queen_2.row - queen_1.row);
    int y_diff = abs(queen_2.column - queen_1.column);
    if (y_diff / x_diff == 1) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
