#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  const WrongAnimal *wrong_meta = new WrongAnimal();
  const WrongAnimal *wrong_i = new WrongCat();

  std::cout << wrong_i->getType() << " " << std::endl;

  wrong_i->makeSound(); // will output the unexpected sound!
  wrong_meta->makeSound();

  delete wrong_meta;
  delete wrong_i;
}