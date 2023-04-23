#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void leakCheck() { system("leaks Fire"); }

int main() {
  // atexit(leakCheck);

  // Animal test;

  Cat another;
  another.makeSound();

  Dog other;
  other.makeSound();

  return 0;
}