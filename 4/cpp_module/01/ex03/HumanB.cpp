#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
  std::cout << _name << " came from somewhere." << std::endl;
}

HumanB::~HumanB() { std::cout << _name << " has gone." << std::endl; }

void HumanB::attack() {
  std::cout << _name << " attacks with their "
            << (_weapon ? _weapon->getType() : "empty hands") << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
 }
