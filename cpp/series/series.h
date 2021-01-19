#if !defined(SERIES_H)
#define SERIES_H

#include <vector>
#include <string>

namespace series {

std::vector<int> digits(const std::string &str, int digits = 1);
std::vector<std::vector<int>> slice(const std::string &str, int digits);

} // namespace series

#endif // SERIES_H
