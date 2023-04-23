#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *brain;

public:
  Cat();
  Cat(const Cat &copy);
  ~Cat();

  Cat &operator=(const Cat &copy);

  void makeSound() const;
  Brain *getBrain() const;
};

#endif // CAT_HPP_