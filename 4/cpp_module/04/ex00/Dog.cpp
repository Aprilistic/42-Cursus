#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog default constructor called" << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog &copy) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = copy;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog assignation operator called" << std::endl;
  if (this != &copy)
    type = copy.type;
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }