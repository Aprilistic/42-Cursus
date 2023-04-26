#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

AForm::AForm()
    : name("default"), is_signed(false), grade_to_sign(1), grade_to_execute(1) {
}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(grade_to_sign),
      grade_to_execute(grade_to_execute) {
  if (grade_to_sign < 1 || grade_to_execute < 1)
    throw AForm::GradeTooHighException();
  if (grade_to_sign > 150 || grade_to_execute > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : name(copy.getName()), is_signed(copy.getIsSigned()),
      grade_to_sign(copy.getGradeToSign()),
      grade_to_execute(copy.getGradeToExecute()) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &copy) {
  if (this != &copy) {
    *const_cast<std::string *>(&this->name) = copy.getName();
    is_signed = copy.is_signed;
    *const_cast<int *>(&this->grade_to_sign) = copy.getGradeToSign();
    *const_cast<int *>(&this->grade_to_execute) = copy.getGradeToExecute();
  }
  return *this;
}

const std::string &AForm::getName() const { return this->name; }

bool AForm::getIsSigned() const { return this->is_signed; }

int AForm::getGradeToSign() const { return this->grade_to_sign; }

int AForm::getGradeToExecute() const { return this->grade_to_execute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_to_sign)
    throw AForm::GradeTooLowException();
  is_signed = true;
}

void AForm::checkAuthority(const Bureaucrat &executor) const {
  if (!is_signed)
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > grade_to_execute)
    throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << form.getName() << ", form grade to sign " << form.getGradeToSign()
      << ", form grade to execute " << form.getGradeToExecute();
  return out;
}
