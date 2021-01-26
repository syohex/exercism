#include "trinary.h"

namespace trinary {

int to_decimal(const std::string &str) {
    const auto pow = [](int n, int power) -> int {
        if (power == 0) {
            return 1;
        }

        int ret = 1;
        for (int i = 1; i <= power; ++i) {
            ret = ret * n;
        }

        return ret;
    };

    int ret = 0;
    int len = str.size();
    for (int i = len - 1, j = 0; i >= 0; --i, ++j) {
        if (!isdigit(static_cast<int>(str[i]))) {
            return 0;
        }

        int v = str[i] - '0';
        ret += v * pow(3, j);
    }

    return ret;
}

} // namespace trinary
