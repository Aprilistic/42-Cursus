#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	public:
		ShrubberyCreationForm(const std::string &target);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		std::string getTarget() const;
		void setTarget(const std::string &target);
		virtual void execute(const Bureaucrat &executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP_