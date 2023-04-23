#include "FragTrap.hpp"
#include <iostream>

int main() {
  FragTrap A("A");
  FragTrap B("B");

  A.attack("B");
  B.takeDamage(A.getAttackDamage());

  B.highFivesGuys();
  A.highFivesGuys();

  return 0;
}