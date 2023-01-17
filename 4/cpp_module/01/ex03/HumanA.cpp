#include "HumanA.hpp"
#include "Weapon.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {
  std::cout << _name << " came from somewhere." << std::endl;
}

HumanA::~HumanA() { std::cout << _name << " has gone." << std::endl; }

void HumanA::attack() {
  std::cout << _name << " attacks with their " << _weapon.getType()
            << std::endl;
}

void HumanA::setWeapon(Weapon weapon) { _weapon = weapon; }
