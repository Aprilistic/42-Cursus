#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

  void execute(const Bureaucrat &executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP_