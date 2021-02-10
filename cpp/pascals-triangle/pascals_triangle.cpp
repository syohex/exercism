#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(int n) {
    std::vector<std::vector<int>> ret;

    for (int i = 0; i < n; ++i) {
        ret.push_back(std::vector<int>{});
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                ret[i].push_back(1);
            } else {
                int v = ret[i - 1][j - 1] + ret[i - 1][j];
                ret[i].push_back(v);
            }
        }
    }
    return ret;
}

} // namespace pascals_triangle
