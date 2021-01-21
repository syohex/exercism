#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <string>
#include <utility>

namespace queen_attack {

class chess_board {
  public:
    chess_board();
    explicit chess_board(std::pair<int, int> white, std::pair<int, int> black);

    bool can_attack() const;
    operator std::string() const;

    const std::pair<int, int> &white() const;
    const std::pair<int, int> &black() const;

  private:
    std::pair<int, int> white_;
    std::pair<int, int> black_;
};

} // namespace queen_attack

#endif // QUEEN_ATTACK_H
