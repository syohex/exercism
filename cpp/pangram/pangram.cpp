#include "pangram.h"

#include <cctype>

namespace pangram {

bool is_pangram(const std::string &str) {
    bool table[26] = {};
    for (char c : str) {
        if (!isalpha(static_cast<int>(c))) {
            continue;
        }

        int lower = std::tolower(static_cast<int>(c));
        int index = lower - 'a';

        table[index] = true;
    }

    for (bool b : table) {
        if (!b) {
            return false;
        }
    }

    return true;
}

} // namespace pangram
