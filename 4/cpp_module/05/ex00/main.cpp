#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat i("Pooh", 150);
    std::cout << i << std::endl;
    i.decrementGrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat j("Piglet", 1);
    std::cout << j << std::endl;
    j.incrementGrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat k("Tigger", 0);
    std::cout << k << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}