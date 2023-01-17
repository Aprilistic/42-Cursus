#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie();
  ~Zombie();

  static Zombie* zombieHorde(int N, std::string name);

  void giveNameToZombie(std::string name);
  void announce(void);
};
#endif
