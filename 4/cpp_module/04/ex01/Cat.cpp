#include "Cat.hpp"

Brain *Cat::getBrain() const {
  if (brain)
    return brain;
  return NULL;
}

Cat::Cat() : Animal(), brain(NULL) {
  std::cout << "Cat default constructor called" << std::endl;
  brain = new Brain();
  type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(), brain(NULL) {
  std::cout << "Cat copy constructor called" << std::endl;
  type = copy.type;
  brain = new Brain(*copy.getBrain());
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat assignation operator called" << std::endl;
  if (this != &copy) {
    type = copy.type;
    *brain = *copy.brain;
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }