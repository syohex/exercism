#include "binary_search.h"

#include <stdexcept>

namespace binary_search {

size_t find(const std::vector<int> &data, int value) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] == value) {
            return mid;
        }

        if (data[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    throw std::domain_error("not found value");
}

} // namespace binary_search
