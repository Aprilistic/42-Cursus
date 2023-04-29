#include "RPN.hpp"

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

  std::string token;
  while (ss >> token) {
    if (isdigit(token[0])) {
      s.push(stod(token));
    } else if (token == "+" || token == "-" || token == "*" || token == "/") {
      int op2 = s.top();
      s.pop();
      int op1 = s.top();
      s.pop();

      if (token == "+") {
        s.push(op1 + op2);
      } else if (token == "-") {
        s.push(op1 - op2);
      } else if (token == "*") {
        s.push(op1 * op2);
      } else if (token == "/") {
        s.push(op1 / op2);
      } else {
        throw std::exception();
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