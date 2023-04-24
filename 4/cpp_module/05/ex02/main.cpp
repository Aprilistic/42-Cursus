#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat Pooh("Pooh", 1);
    Form form1("form1", 1, 1);
    Pooh.signForm(form1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat Eeyore("Eeyore", 10);
    Form form2("form2", 1, 1);
    Eeyore.signForm(form2);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}