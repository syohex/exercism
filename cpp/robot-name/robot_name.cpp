#include "robot_name.h"

#include <cassert>
#include <random>

namespace robot_name {

std::set<std::string> robot::table_;

robot::robot() {
    set_random_name();
}

const std::string &robot::name() const {
    return name_;
}

void robot::reset() {
    set_random_name();
}

std::string robot::set_random_name() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> char_distribution{'A', 'Z'};
    std::uniform_int_distribution<int> num_distribution{'0', '9'};

    while (true) {
        std::string ret;
        for (int i = 0; i < 2; ++i) {
            ret += char_distribution(generator);
        }

        for (int i = 0; i < 3; ++i) {
            ret += num_distribution(generator);
        }

        if (table_.find(ret) == table_.end()) {
            table_.insert(ret);
            name_ = ret;
            return ret;
        }
    }

    assert(!"never reach here");
    return "";
}

} // namespace robot_name
