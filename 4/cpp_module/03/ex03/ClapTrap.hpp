#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

#define HIT_POINTS 10
#define ENERGY_POINTS 10
#define ATTACK_DAMAGE 0
#define DEFAULT_NAME "Default"
class ClapTrap {
private:
  std::string name;
  int hit_points;
  int energy_points;
  int attack_damage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &copy);
  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &copy);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);


  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

  void setName(std::string name);
  void setHitPoints(int hit_points);
  void setEnergyPoints(int energy_points);
  void setAttackDamage(int attack_damage);
};

#endif // CLAPTRAP_HPP_