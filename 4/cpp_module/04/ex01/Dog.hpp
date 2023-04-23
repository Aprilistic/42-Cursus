#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain;

public:
  Dog();
  Dog(const Dog &copy);
  ~Dog();

  Dog &operator=(const Dog &copy);

  void makeSound() const;
  Brain *getBrain() const;
};

#endif // DOG_HPP_