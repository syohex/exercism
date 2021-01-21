#include "queen_attack.h"

#include <cmath>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board() : white_(std::make_pair(0, 3)), black_(std::make_pair(7, 3)) {
}

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : white_(std::move(white)), black_(std::move(black)) {
    if (white_ == black_) {
        throw std::domain_error("invalid position");
    }
}

bool chess_board::can_attack() const {
    if (white_.first == black_.first) {
        return true;
    }

    if (white_.second == black_.second) {
        return true;
    }

    int v = std::abs(white_.second - black_.second) / std::abs(white_.first - black_.first);
    return v == 1;
}

chess_board::operator std::string() const {
    std::string ret;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (j != 0) {
                ret += " ";
            }

            if (i == white_.first && j == white_.second) {
                ret += "W";
            } else if (i == black_.first && j == black_.second) {
                ret += "B";
            } else {
                ret += "_";
            }
        }
        ret += "\n";
    }

    return ret;
}

const std::pair<int, int> &chess_board::white() const {
    return white_;
}
const std::pair<int, int> &chess_board::black() const {
    return black_;
}

} // namespace queen_attack
