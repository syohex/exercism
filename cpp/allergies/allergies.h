#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace allergies {

class allergy_test {
  public:
    explicit allergy_test(int n);

    bool is_allergic_to(const std::string &item) const;

    std::unordered_set<std::string> get_allergies() const;

  private:
    int name_to_value(const std::string &name) const;

    std::unordered_map<std::string, int> table_;
    int value_;
};

} // namespace allergies

#endif // ALLERGIES_H
