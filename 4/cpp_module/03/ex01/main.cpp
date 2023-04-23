#include "ScavTrap.hpp"
#include <iostream>

int main(){
  ScavTrap A("A");
  ScavTrap B("B");

  A.attack("B");
  B.takeDamage(A.getAttackDamage());

  B.guardGate();

  A.setAttackDamage(50);

  A.attack("B");
  B.takeDamage(A.getAttackDamage());

  B.beRepaired(10);

  A.attack("B");
  B.takeDamage(A.getAttackDamage());

  return 0;
}