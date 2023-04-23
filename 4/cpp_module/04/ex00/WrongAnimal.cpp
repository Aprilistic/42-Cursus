#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Undefined") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = copy;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
  std::cout << "WrongAnimal assignation operator called" << std::endl;
  if (this != &copy)
    type = copy.type;
  return *this;
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal sound" << std::endl; }
