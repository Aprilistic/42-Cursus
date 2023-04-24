#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  AForm::checkAuthority(executor);
  std::ofstream file;
  std::string filename = getName() + "_shrubbery";
  file.open(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << filename << std::endl;
    return;
  }
  std::string tree =
      "                                              .         ;   \n"
      " .              .              ;%     ;;   \n"
      "   ,           ,                :;%  %;   \n"
      "    :         ;                   :;%;'     .,   \n"
      "  ,.        %;     %;            ;        %;'    ,;\n"
      "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
      "  %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
      "  ;%;      %;        ;%;        % ;%;  ,%;'\n"
      "  `%;.     ;%;     %;'         `;%%;.%;'\n"
      "  `:;%.    ;%%. %@;        %; ;@%;%'\n"
      "    `:%;.  :;bd%;          %;@%;'\n"
      "      `@%:.  :;%.         ;@@%;'   \n"
      "        `@%.  `;@%.      ;@@%;         \n"
      "          `@%%. `@%%    ;@@%;        \n"
      "            ;@%. :@%%  %@@%;       \n"
      "              %@bd%%%bd%%:;     \n"
      "                #@%%%%%:;;\n"
      "                %@@%%%::;\n"
      "                %@@@%(o);  . '         \n"
      "                %@@@o%;:(.,'         \n"
      "            `.. %@@@o%::;         \n"
      "               `)@@@o%::;         \n"
      "                %@@(o)::;        \n"
      "               .%@@@@%::;         \n"
      "               ;%@@@@%::;.          \n"
      "              ;%@@@@%%:;;;.  \n"
      "          ...;%@@@@@%%:;;;;,..    Gilo97";
  file << tree << std::endl;
  file.close();
}