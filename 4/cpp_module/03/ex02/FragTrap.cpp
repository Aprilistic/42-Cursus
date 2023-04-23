#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
  std::cout << "FragTrap " << this->getName() << " default constructor called"
            << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
  std::cout << "FragTrap " << this->getName() << " constructor called"
            << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
  std::cout << "FragTrap " << this->getName() << " copy constructor called"
            << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->getName() << " destructor called"
            << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
  std::cout << "FragTrap " << this->getName() << " assignation operator called"
            << std::endl;
  if (this != &copy) {
    this->setName(copy.getName());
    this->setHitPoints(copy.getHitPoints());
    this->setEnergyPoints(copy.getEnergyPoints());
    this->setAttackDamage(copy.getAttackDamage());
  }
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->getName() << " high fives very positively"
            << std::endl;
}