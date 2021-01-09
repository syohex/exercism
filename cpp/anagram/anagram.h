#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <vector>
#include <initializer_list>
#include <map>

namespace anagram {

class anagram {
  public:
    explicit anagram(std::string word);

    std::vector<std::string> matches(std::initializer_list<std::string> words);

  private:
    std::string word_;
    std::map<char, int> word_map_;
};

} // namespace anagram

#endif // ANAGRAM_H