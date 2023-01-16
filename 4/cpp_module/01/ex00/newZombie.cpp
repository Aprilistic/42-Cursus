#include "Zombie.hpp"

#include <string>

Zombie *Zombie::newZombie(std::string name) { return (new Zombie(name)); }
