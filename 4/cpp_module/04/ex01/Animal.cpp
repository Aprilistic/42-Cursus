#include "Animal.hpp"

Animal::Animal() : type("Undefined") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &copy)
		type = copy.type;
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

