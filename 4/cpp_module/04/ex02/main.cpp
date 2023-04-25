#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void leakCheck() { system("leaks Abstract"); }

int main() {
  // atexit(leakCheck);

  // const Animal *j = new Dog();
  // const Animal *i = new Cat();

  // std::cout << j->getType() << " " << std::endl;
  // std::cout << i->getType() << " " << std::endl;

  // i->makeSound(); // will output the cat sound!
  // j->makeSound();

  // delete j;
  // delete i;

  // const Animal *animals[4];
  // for (int i = 0; i < 2; i++)
  //   animals[i] = new Cat();
  // for (int i = 2; i < 4; i++)
  //   animals[i] = new Dog();
  // for (int i = 0; i < 4; i++)
  //   delete animals[i];

  // Cat *cat1 = new Cat();
  // cat1->getBrain()->setIdea(0, "Nyaa");
  // std::cout << "cat1 is thinking " << cat1->getBrain()->getIdea(0) <<
  // std::endl; Cat cat2 = *cat1;

  // delete cat1;
  // cat2.makeSound();
  // std::cout << "cat2 is thinking " << cat2.getBrain()->getIdea(0) <<
  // std::endl;

  Cat another;
  another.makeSound();

  Dog other;
  other.makeSound();

  return 0;
}