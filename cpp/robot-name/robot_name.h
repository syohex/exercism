#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <set>

namespace robot_name {

class robot {
  public:
    robot();

    const std::string &name() const;
    void reset();

  private:
    std::string set_random_name();

    std::string name_;
    static std::set<std::string> table_;
};

} // namespace robot_name

#endif // ROBOT_NAME_H
