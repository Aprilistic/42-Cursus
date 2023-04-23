#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &copy);
  ~Dog();

  Dog &operator=(const Dog &copy);

  void makeSound() const;
};

#endif // DOG_HPP_