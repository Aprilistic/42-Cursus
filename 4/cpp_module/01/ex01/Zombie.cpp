#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
  std::cout << "A zombie has been created...\n";
}
Zombie::~Zombie() { std::cout << "'" << name << "' has been killed...\n"; }

void Zombie::giveNameToZombie(std::string name) {
  this->name = name;
}

void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
