#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

Form::Form()
    : name("default"), is_signed(false), grade_to_sign(1), grade_to_execute(1) {
}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(grade_to_sign),
      grade_to_execute(grade_to_execute) {
  if (grade_to_sign < 1 || grade_to_execute < 1)
    throw Form::GradeTooHighException();
  if (grade_to_sign > 150 || grade_to_execute > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form &copy)
    : name(copy.getName()), is_signed(copy.getIsSigned()),
      grade_to_sign(copy.getGradeToSign()),
      grade_to_execute(copy.getGradeToExecute()) {}

Form::~Form() {}

Form &Form::operator=(const Form &copy) {
  if (this != &copy) {
    *const_cast<std::string *>(&this->name) = copy.getName();
    is_signed = copy.is_signed;
    *const_cast<int *>(&this->grade_to_sign) = copy.getGradeToSign();
    *const_cast<int *>(&this->grade_to_execute) = copy.getGradeToExecute();
  }
  return *this;
}

const std::string &Form::getName() const { return this->name; }

bool Form::getIsSigned() const { return this->is_signed; }

int Form::getGradeToSign() const { return this->grade_to_sign; }

int Form::getGradeToExecute() const { return this->grade_to_execute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_to_sign)
    throw Form::GradeTooLowException();
  is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  out << form.getName() << ", form grade to sign " << form.getGradeToSign()
      << ", form grade to execute " << form.getGradeToExecute();
  return out;
}
