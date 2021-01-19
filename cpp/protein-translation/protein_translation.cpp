#include "protein_translation.h"

#include <map>
#include <algorithm>
#include <set>

namespace protein_translation {

std::vector<std::string> proteins(const std::string &str) {
    // clang-format off
    std::map<std::string, std::string> table{
        {"AUG", "Methionine"},

        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},

        {"UUA", "Leucine"},
        {"UUG", "Leucine"},

        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},

        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},

        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},

        {"UGG", "Tryptophan"},

        {"UAA", ""},
        {"UAG", ""},
        {"UGA", ""},
    };
    // clang-format on

    std::vector<std::string> ret;
    std::set<std::string> used;
    size_t pos = 0;
    while (pos < str.size()) {
        bool found = false;
        for (const auto &it : table) {
            const auto &key = it.first;
            if (str.size() - pos < key.size()) {
                continue;
            }

            if (std::equal(key.begin(), key.end(), str.begin() + pos)) {
                if (it.second.empty()) { // STOP
                    return ret;
                }

                pos += key.size();
                if (used.find(key) == used.end()) {
                    ret.push_back(it.second);
                    used.insert(key);
                }

                found = true;
                break;
            }
        }

        if (!found) {
            break;
        }
    }

    return ret;
}

} // namespace protein_translation
