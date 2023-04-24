#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &copy);
  ~Bureaucrat();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  Bureaucrat &operator=(const Bureaucrat &copy);

  const std::string &getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  
  void signForm(AForm &form) const;
  void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP_