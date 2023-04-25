#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string literal) : literal(literal) {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
  literal = copy.literal;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy) {
  literal = copy.literal;
  return *this;
}

ScalarConverter::operator char() const {
  int val;
  try {
    val = std::stoi(literal);
  } catch (std::exception &e) {
    throw ImpossibleException();
  }
  if (val < 0 || val > 127)
    throw ImpossibleException();
  if (val < 32 || val > 126)
    throw NonDisplayableException();
  return static_cast<char>(val);
}

ScalarConverter::operator int() const {
  try {
    double val = std::stoi(literal);
    if (val < std::numeric_limits<int>::min() ||
        std::numeric_limits<int>::max() < val)
      throw ImpossibleException();
  } catch (...) {
    throw ImpossibleException();
  }
}