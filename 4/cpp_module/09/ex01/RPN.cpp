#include "RPN.hpp"
#include <cctype>

RPN::RPN() {}

RPN::RPN(RPN const &copy) { (void)copy; }

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &copy) {
  (void)copy;
  return *this;
}

int RPN::evaluateRPN(const std::string &str) {
  std::stack<int> s;
  std::stringstream ss(str);

  char token;
  while (true) {
    ss >> token;
    if (ss.eof()) {
      break;
    } else if (ss.fail()) {
      throw std::exception();
    }

    if (std::isspace(token)) {
      continue;
    } else if (std::isdigit(token)) {
      s.push(token - '0');
    } else if (token == '+' || token == '-' || token == '*' || token == '/') {
      if (s.size() < 2) {
        throw std::exception();
      }
      int op2 = s.top();
      s.pop();
      int op1 = s.top();
      s.pop();

      switch (token) {
      case '+':
        s.push(op1 + op2);
        break;
      case '-':
        s.push(op1 - op2);
        break;
      case '*':
        s.push(op1 * op2);
        break;
      case '/':
        if (op2 == 0) {
          throw std::exception();
        }
        s.push(op1 / op2);
        break;
      }
    } else {
      throw std::exception();
    }
  }
  if (s.size() != 1) {
    throw std::exception();
  }
  return s.top();
}
