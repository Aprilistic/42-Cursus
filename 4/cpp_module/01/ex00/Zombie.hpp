#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
  std::string name;

  Zombie();

public:
  Zombie(std::string name);
  ~Zombie();

  static Zombie *newZombie(std::string name);
  static void randomChump(std::string name);
  void announce(void);
};
#endif