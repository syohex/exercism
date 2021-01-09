#include "anagram.h"

#include <map>
#include <algorithm>
#include <cctype>

namespace anagram {

anagram::anagram(std::string word) : word_(std::move(word)) {
    std::transform(word_.begin(), word_.end(), word_.begin(), std::tolower);

    for (char c : word_) {
        ++word_map_[c];
    }
}

std::vector<std::string> anagram::matches(std::initializer_list<std::string> words) {
    std::vector<std::string> ret;
    for (const auto &word : words) {
        auto tmp = word;
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), std::tolower);

        if (tmp == word_) {
            continue;
        }

        std::map<char, int> m;
        for (char c : tmp) {
            ++m[c];
        }

        if (word_map_ == m) {
            ret.push_back(word);
        }
    }

    return ret;
}

} // namespace anagram
