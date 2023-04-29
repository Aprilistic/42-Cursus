#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./RPN <expression>" << std::endl;
    return 1;
  }
  std::string str(argv[1]);

  try {
    std::cout << RPN::evaluateRPN(str) << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  return 0;
}