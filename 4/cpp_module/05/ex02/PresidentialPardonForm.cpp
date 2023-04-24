#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  AForm::operator=(copy);
  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  AForm::checkAuthority(executor);
  std::cout << getName() << " has been pardoned by Zafod Beeblebrox"
            << std::endl;
}