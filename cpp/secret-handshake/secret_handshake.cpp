#include "secret_handshake.h"

#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(int n) {
    std::vector<std::string> ret;
    if ((n & 0x1) == 0x1) {
        ret.push_back("wink");
    }
    if ((n & 0x2) == 0x2) {
        ret.push_back("double blink");
    }
    if ((n & 0x4) == 0x4) {
        ret.push_back("close your eyes");
    }
    if ((n & 0x8) == 0x8) {
        ret.push_back("jump");
    }
    if ((n & 0x10) == 0x10) {
        std::reverse(ret.begin(), ret.end());
    }

    return ret;
}

} // namespace secret_handshake
