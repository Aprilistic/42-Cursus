#include <iostream>
#include <string.h>
#include <string>

int main() {
  std::string brain = "HI THIS IS BRAIN";
  std::string *stringPTR = &brain;
  std::string &stringREF = brain;

  std::cout << static_cast<void *>(&brain) << std::endl;
  std::cout << static_cast<void *>(&stringPTR) << std::endl;
  std::cout << static_cast<void *>(&stringREF) << std::endl;

  std::cout << std::endl;

  std::cout << brain << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;
}
