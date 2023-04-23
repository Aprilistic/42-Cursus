#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string name;

public:
  DiamondTrap();
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &copy);
  ~DiamondTrap();

  DiamondTrap &operator=(const DiamondTrap &copy);

  void attack(const std::string &target);
  void whoAmI();
};

#endif // DIAMONDTRAP_HPP_