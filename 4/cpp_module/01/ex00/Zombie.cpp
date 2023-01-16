#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
  this->name = name;
  std::cout << "'" << name << "' has been created...\n";
}
Zombie::~Zombie() { std::cout << "'" << name << "' has been killed...\n"; }

void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}