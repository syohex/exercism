#include "series.h"

#include <stdexcept>

namespace series {

std::vector<int> digits(const std::string &str, int digits) {
    int len = str.size();
    if (len < digits) {
        throw std::domain_error("invalid argument");
    }

    std::vector<int> ret;
    for (int i = 0; i <= len - digits; ++i) {
        ret.emplace_back(std::stoi(str.substr(i, digits)));
    }

    return ret;
}

std::vector<std::vector<int>> slice(const std::string &str, int digits) {
    int len = str.size();
    if (len < digits) {
        throw std::domain_error("invalid argument");
    }

    std::vector<std::vector<int>> ret;
    for (int i = 0; i <= len - digits; ++i) {
        std::vector<int> v;
        for (int j = 0; j < digits; ++j) {
            v.push_back(str[i + j] - '0');
        }
        ret.push_back(std::move(v));
    }

    return ret;
}

} // namespace series
