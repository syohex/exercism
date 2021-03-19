#include "allergies.h"

namespace allergies {

allergy_test::allergy_test(int n) : value_(n) {
    table_ = std::unordered_map<std::string, int>{
        {"eggs", 1},      {"peanuts", 2},    {"shellfish", 4}, {"strawberries", 8},
        {"tomatoes", 16}, {"chocolate", 32}, {"pollen", 64},   {"cats", 128},
    };
}

bool allergy_test::is_allergic_to(const std::string &item) const {
    return (value_ & name_to_value(item)) != 0;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> ret;
    for (const auto &it : table_) {
        if ((value_ & it.second) != 0) {
            ret.insert(it.first);
        }
    }

    return ret;
}

int allergy_test::name_to_value(const std::string &name) const {
    return table_.at(name);
}

} // namespace allergies
