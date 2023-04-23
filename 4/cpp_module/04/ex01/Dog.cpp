#include "Dog.hpp"

Brain *Dog::getBrain() const {
  if (brain)
    return brain;
  return NULL;
}

Dog::Dog() : Animal(), brain(NULL) {
  std::cout << "Dog default constructor called" << std::endl;
  brain = new Brain();
  type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(), brain(NULL) {
  std::cout << "Dog copy constructor called" << std::endl;
  type = copy.type;
  brain = new Brain(*copy.getBrain());
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain;
}

Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog assignation operator called" << std::endl;
  if (this != &copy) {
    type = copy.type;
    *brain = *copy.brain;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }