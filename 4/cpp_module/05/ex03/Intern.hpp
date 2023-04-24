#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
  Intern();
  Intern(Intern const &copy);
  ~Intern();

  Intern &operator=(Intern const &copy);

  class FormNotFoundException : public std::exception {
  public:
    const char *what() const throw();
  };

  AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif // INTERN_HPP_