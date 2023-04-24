#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()),
      target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  if (this != &copy) {
    this->target = copy.getTarget();
  }
  return *this;
}

std::string ShrubberyCreationForm::getTarget() const { return this->target; }

void ShrubberyCreationForm::setTarget(const std::string &target) {
  this->target = target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  AForm::execute(executor);
  std::ofstream file;
  std::string filename = target + "_shrubbery";
  file.open(filename.c_str());
  if (!file.is_open()) {
    std::cout << "Error: could not open file " << filename << std::endl;
    return;
  }
  file << R"(
        .
        .         ;  
           .              .              ;%     ;;   
             ,           ,                :;%  %;   
              :         ;                   :;%;'     .,   
     ,.        %;     %;            ;        %;'    ,;
       ;       ;%;  %%;        ,     %;    ;%;    ,%'
        %;       %;%;      ,  ;       %;  ;%;   ,%;' 
         ;%;      %;        ;%;        % ;%;  ,%;'
          `%;.     ;%;     %;'         `;%%;.%;'
           `:;%.    ;%%. %@;        %; ;@%;%' 
              `:%;.  :;bd%;          %;@%;' 
                `@%:.  :;%.         ;@@%;'   
                  `@%.  `;@%.      ;@@%;         
                    `@%%. `@%%    ;@@%;        
                      ;@%. :@%%  %@@%;       
                        %@bd%%%bd%%:;     
                          #@%%%%%:;;
                          %@@%%%::;
                          %@@@%(o);  . '         
                          %@@@o%;:(.,'         
                      `.. %@@@o%::;         
                         `)@@@o%::;         
                          %@@(o)::;        
                         .%@@@@%::;         
                         ;%@@@@%::;.          
                        ;%@@@@%%:;;;. 
                    ...;%@@@@@%%:;;;;,..;
    )" << std::endl;
  file.close();
}