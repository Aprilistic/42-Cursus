#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  AForm::checkAuthority(executor);
  std::cout << "* drilling noises *" << std::endl;
  if (rand() % 2)
    std::cout << getName() << " has been robotomized successfully" << std::endl;
  else
    std::cout << "Robotomization of " << getName() << " failed" << std::endl;
}