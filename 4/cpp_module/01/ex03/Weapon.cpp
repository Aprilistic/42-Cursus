#include "Weapon.hpp"

#include <iostream>
#include <string>

Weapon::Weapon(std::string type) : type(type) {
  std::cout << "\'" << type << "\' equipped" << std::endl;
};

const std::string &Weapon::getType() const { return type; }

void Weapon::setType(std::string type) { this->type = type; }
