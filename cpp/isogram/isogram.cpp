#include "isogram.h"

#include <cctype>

namespace isogram {

bool is_isogram(const std::string &str) {
    bool table[26] = {};
    for (char c : str) {
        if (!isalpha(static_cast<int>(c))) {
            continue;
        }

        int index = tolower(static_cast<int>(c)) - 'a';
        if (table[index]) {
            return false;
        }

        table[index] = true;
    }

    return true;
}

} // namespace isogram
