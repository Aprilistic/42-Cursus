#include "Zombie.hpp"
#include <cstdlib>

void leaks() { system("leaks Moar_brainz!"); }

int main() {
  //atexit(&leaks);

  Zombie *horde1 = Zombie::zombieHorde(5, "dude");
  //Zombie *horde2 = Zombie::zombieHorde(5, "guy");

  horde1[4].announce();
  //horde2[0].announce();

  delete[] horde1;
  //delete[] horde2;

  return 0;
}
