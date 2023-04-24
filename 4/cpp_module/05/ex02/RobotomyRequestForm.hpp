#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <cstdlib>
#include <string>

class RobotomyRequestForm : public AForm{
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

	void execute(const Bureaucrat &executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP_