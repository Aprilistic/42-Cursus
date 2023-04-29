#ifndef RPN_HPP_
#define RPN_HPP_

#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
private:
  RPN();
  RPN(RPN const &copy);
  ~RPN();

  RPN &operator=(RPN const &copy);

public:
  static int evaluateRPN(const std::string &str);
};

#endif // RPN_HPP_