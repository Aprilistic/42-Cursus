#ifndef FORM_HPP_
#define FORM_HPP_


#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
private:
  const std::string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_execute;

public:
  Form();
  Form(const std::string &name, int grade_to_sign, int grade_to_execute);
  Form(const Form &copy);
  ~Form();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  Form &operator=(const Form &copy);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // FORM_HPP_