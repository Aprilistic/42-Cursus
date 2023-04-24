#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  Bureaucrat Pooh("Pooh", 1);
  Bureaucrat Piglet("Piglet", 150);
  Bureaucrat Tigger("Tigger", 42);

  // AForm form1("Form1", 1, 1);
  ShrubberyCreationForm form1("Form1");
  RobotomyRequestForm form2("Form2");
  PresidentialPardonForm form3("Form3");

  std::cout << Pooh << std::endl;

  Pooh.executeForm(form1);
  Pooh.executeForm(form2);
  Pooh.executeForm(form3);

  Pooh.signForm(form1);
  Pooh.signForm(form2);
  Pooh.signForm(form3);

  Pooh.executeForm(form1);
  Pooh.executeForm(form2);
  Pooh.executeForm(form3);

  Piglet.executeForm(form1);
  Piglet.executeForm(form2);
  Piglet.executeForm(form3);

  Tigger.executeForm(form1);
  Tigger.executeForm(form2);
  Tigger.executeForm(form3);
}