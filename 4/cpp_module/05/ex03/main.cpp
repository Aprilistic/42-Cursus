#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

// void leakCheck(){
//   system("leaks Coffee");
// }

int main() {
  // atexit(&leakCheck);
  Bureaucrat Pooh("Pooh", 1);
  Bureaucrat Piglet("Piglet", 150);
  Bureaucrat Tigger("Tigger", 42);

  Intern  Eeyore;
  AForm   *form1 = Eeyore.makeForm("shruberry creation", "Form1");
  AForm   *form2 = Eeyore.makeForm("robotomy request", "Form2");
  AForm   *form3 = Eeyore.makeForm("presidential pardon", "Form3");
  Eeyore.makeForm("wrong", "Form4");

  Pooh.signForm(*form1);
  Pooh.signForm(*form2);

  Pooh.executeForm(*form1);
  Pooh.executeForm(*form2);
  Pooh.executeForm(*form3);

  Piglet.signForm(*form1);

  Tigger.executeForm(*form2);


  delete form1;
  delete form2;
  delete form3;
}