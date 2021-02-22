#include "acronym.h"

#include <cctype>

namespace acronym {

std::string acronym(const std::string &str) {
    std::string ret;
    size_t pos = 0;

    while (pos < str.size()) {
        while (pos < str.size() && !std::isalpha(str[pos])) {
            ++pos;
        }

        ret.push_back(std::toupper(str[pos]));

        while (pos < str.size() && std::isalpha(str[pos])) {
            ++pos;
        }
    }

    return ret;
}

} // namespace acronym
