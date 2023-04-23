#include "ClapTrap.hpp"
#include <iostream>

int main(){
  ClapTrap aaa("aaa");
  ClapTrap bbb("bbb");
  ClapTrap mmm;

  aaa.setAttackDamage(6);
  aaa.attack("bbb");
  bbb.takeDamage(aaa.getAttackDamage());

  aaa.attack("bbb");
  bbb.takeDamage(aaa.getAttackDamage());

  aaa.setEnergyPoints(0);
  aaa.attack("mmm");
}