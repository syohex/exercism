#include "binary.h"

namespace binary {

unsigned int convert(const std::string& str) {
    unsigned int ret = 0;
    for (char c : str) {
        if (!(c == '0' || c == '1')) {
            return 0;
        }

        ret = (ret << 1) + c - '0';
    }
    return ret;
}

}  // namespace binary
