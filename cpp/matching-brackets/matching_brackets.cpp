#include "matching_brackets.h"

#include <stack>

namespace matching_brackets {

bool check(const std::string &str) {
    std::stack<char> s;

    for (char c : str) {
        switch (c) {
        case '[':
        case '{':
        case '(':
            s.push(c);
            break;
        case ']':
            if (s.empty() || s.top() != '[') {
                return false;
            }

            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{') {
                return false;
            }

            s.pop();
            break;
        case ')':
            if (s.empty() || s.top() != '(') {
                return false;
            }

            s.pop();
            break;
        }
    }

    return s.empty();
}

} // namespace matching_brackets
