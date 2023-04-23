#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &copy);
  ~ScavTrap();

  ScavTrap &operator=(const ScavTrap &copy);

  void guardGate();
};

#endif // SCAVTRAP_HPP_