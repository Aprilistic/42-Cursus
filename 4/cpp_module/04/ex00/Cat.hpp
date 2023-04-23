#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat &operator=(const Cat &copy);

		void makeSound() const;
};

#endif // CAT_HPP_