#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
  std::string _name;
  Weapon &_weapon;

public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();

  void attack();
  void setWeapon(Weapon weapon);
};

#endif
