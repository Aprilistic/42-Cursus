#include "Harl.hpp"

#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Invalid arguments count. One argument is allowed."
              << std::endl;
    std::cout << "Avaliable commands: DEBUG, INFO, WARNING, ERROR" << std::endl;
    return 0;
  }

  Harl halhalhal;

  halhalhal.complain(argv[1]);
}
