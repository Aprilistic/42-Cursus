#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(){
	std::cout << "Cat copy constructor called" << std::endl;
	type = copy.getType();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
		type = copy.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}