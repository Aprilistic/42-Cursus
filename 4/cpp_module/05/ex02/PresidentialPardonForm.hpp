#ifndef PRESENTIALPARDONFORM_HPP_
#define PRESENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  PresidentialPardonForm();

public:
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

  void execute(const Bureaucrat &executor) const;
};

#endif // PRESENTIALPARDONFORM_HPP_