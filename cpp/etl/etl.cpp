#include "etl.h"

#include <cctype>

namespace etl {

std::map<char, int> transform(const std::map<int, std::vector<char>> &input) {
    std::map<char, int> ret;

    for (const auto &it : input) {
        for (int n : it.second) {
            char c = std::tolower(n);
            ret[c] = it.first;
        }
    }

    return ret;
}

} // namespace etl
