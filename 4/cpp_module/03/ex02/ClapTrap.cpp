#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name(DEFAULT_NAME), hit_points(HIT_POINTS), energy_points(ENERGY_POINTS),
      attack_damage(ATTACK_DAMAGE) {
  std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(HIT_POINTS), energy_points(ENERGY_POINTS),
      attack_damage(ATTACK_DAMAGE) {
  std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  *this = copy;
  std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
  name = copy.name;
  hit_points = copy.hit_points;
  energy_points = copy.energy_points;
  attack_damage = copy.attack_damage;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (!hit_points) {
    std::cout << "ClapTrap " << name << " is already dead" << std::endl;
    return;
  } else if (!energy_points) {
    std::cout << "ClapTrap " << name << " has no energy" << std::endl;
    return;
  }
  energy_points--;
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
            << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!hit_points) {
    std::cout << "ClapTrap " << name << " is already dead" << std::endl;
    return;
  } else if (hit_points <= (int)amount) {
    std::cout << "ClapTrap " << name << " is dead" << std::endl;
    hit_points = 0;
    return;
  }
  hit_points -= amount;
  std::cout << "ClapTrap " << name << " takes " << amount
            << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!hit_points) {
    std::cout << "ClapTrap " << name << " is already dead" << std::endl;
    return;
  } else if (!energy_points) {
    std::cout << "ClapTrap " << name << " has no energy" << std::endl;
    return;
  }
  energy_points--;
  hit_points += amount;
  std::cout << "ClapTrap " << name << " is healed by " << amount << " points!"
            << std::endl;
}

std::string ClapTrap::getName() const { return name; }
int ClapTrap::getHitPoints() const { return hit_points; }
int ClapTrap::getEnergyPoints() const { return energy_points; }
int ClapTrap::getAttackDamage() const { return attack_damage; }

void ClapTrap::setName(std::string name) { this->name = name; }
void ClapTrap::setHitPoints(int hit_points) { this->hit_points = hit_points; }
void ClapTrap::setEnergyPoints(int energy_points) {
  this->energy_points = energy_points;
}
void ClapTrap::setAttackDamage(int attack_damage) {
  this->attack_damage = attack_damage;
}