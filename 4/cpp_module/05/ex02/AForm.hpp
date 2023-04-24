#ifndef AFORM_HPP_
#define AFORM_HPP_


#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
private:
  const std::string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_execute;

public:
  AForm();
  AForm(const std::string &name, int grade_to_sign, int grade_to_execute);
  AForm(const AForm &copy);
  virtual ~AForm() = 0;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  AForm &operator=(const AForm &copy);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AFORM_HPP_