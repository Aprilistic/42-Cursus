#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap " << this->getName() << " default constructor called"
            << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "ScavTrap " << this->getName() << " constructor called"
            << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
  std::cout << "ScavTrap " << this->getName() << " copy constructor called"
            << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->getName() << " destructor called"
            << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
  std::cout << "ScavTrap " << this->getName() << " assignation operator called"
            << std::endl;
  if (this != &copy) {
    this->setName(copy.getName());
    this->setHitPoints(copy.getHitPoints());
    this->setEnergyPoints(copy.getEnergyPoints());
    this->setAttackDamage(copy.getAttackDamage());
  }
  return *this;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode"
            << std::endl;
}
