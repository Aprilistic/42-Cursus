#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name") {
  this->name = "default";
  this->setHitPoints(FragTrap::getHitPoints());
  this->setEnergyPoints(ScavTrap::getEnergyPoints());
  this->setAttackDamage(FragTrap::getAttackDamage());

  std::cout << "DiamondTrap " << name << " default constructor called"
            << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name") {
  this->name = name;
  this->setHitPoints(FragTrap::getHitPoints());
  this->setEnergyPoints(ScavTrap::getEnergyPoints());
  this->setAttackDamage(FragTrap::getAttackDamage());
  std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
  std::cout << "DiamondTrap " << name << " copy constructor called"
            << std::endl;
  this->name = copy.getName();
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
  std::cout << "DiamondTrap " << name << " assignation operator called"
            << std::endl;
  this->name = copy.name;
  this->setName(copy.getName() + "_clap_name");
  this->setHitPoints(copy.getHitPoints());
  this->setEnergyPoints(copy.getEnergyPoints());
  this->setAttackDamage(copy.getAttackDamage());
  return *this;
}

std::string DiamondTrap::getName() const { return this->name; }

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << this->name << std::endl;
  std::cout << "ScavTrap name: " << ScavTrap::getName() << std::endl;
}