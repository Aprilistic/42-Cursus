#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal &operator=(const Animal &copy);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif // ANIMAL_HPP_