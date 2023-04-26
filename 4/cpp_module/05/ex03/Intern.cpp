#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &copy) { (void)copy; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &copy) {
  (void)copy;
  return *this;
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}

//form name: "shruberry creation", "robotomy request", "presidential pardon"
AForm *Intern::makeForm(std::string const &form_name,
                        std::string const &target) {

  std::string form_names[3] = {"shruberry creation", "robotomy request",
                               "presidential pardon"};

  try {
    for (int i = 0; i < 3; i++) {
      if (form_name == form_names[i]) {
        std::cout << "Intern creates " << form_name << "Form" << std::endl;
        switch (i) {
        case 0:
          return new ShrubberyCreationForm(target);
        case 1:
          return new RobotomyRequestForm(target);
        case 2:
          return new PresidentialPardonForm(target);
        }
      }
    }
    throw FormNotFoundException();
  } catch (FormNotFoundException &e) {
    std::cerr << "Intern failed to create form because of " << e.what()
              << std::endl;
    return nullptr;
  }
}