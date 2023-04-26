#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade()){}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  if (this != &copy) {
    *const_cast<std::string *>(&this->name) = copy.getName();
    this->grade = copy.grade;
  }
  return *this;
}

const std::string &Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade() {
  if (this->grade - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade++;
}

void Bureaucrat::signForm(Form &form) const {
  try {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cerr << this->name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}
