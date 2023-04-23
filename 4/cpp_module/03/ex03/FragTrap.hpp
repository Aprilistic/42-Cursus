#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &copy);
  ~FragTrap();

  FragTrap &operator=(const FragTrap &copy);

  void highFivesGuys();
};

#endif // FRAGTRAP_HPP_