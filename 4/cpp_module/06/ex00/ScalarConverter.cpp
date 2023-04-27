#include "ScalarConverter.hpp"
#include <cstdlib>
#include <sstream>

double ScalarConverter::doubleValue = 0;
float ScalarConverter::floatValue = 0;
int ScalarConverter::intValue = 0;
char ScalarConverter::charValue = 0;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) { (void)copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy) {
  (void)copy;
  return *this;
}

void ScalarConverter::convert(const std::string &str) {
  switch (parseString(str)) {
  case CHAR:
    fromChar();
    break;
  case INT:
    fromInt();
    break;
  case FLOAT:
    fromFloat();
    break;
  case DOUBLE:
    fromDouble();
    break;
  case PSEUDO:
    fromPseudo();
    break;
  default:
    std::cout << "Invalid" << std::endl;
  }
}

bool ScalarConverter::isChar(const std::string &str) {
  if (str.length() == 1 && isprint(str[0])) {
    charValue = str[0];
    return true;
  }
  return false;
}

bool ScalarConverter::isValue(const std::string &str) {
  std::string lol = str;
  if (lol[lol.length() - 1] == 'f')
    lol = lol.substr(0, lol.length() - 1);
  std::stringstream ss(lol);

  double temp;
  ss >> temp;
  if (ss.fail() || !ss.eof())
    return false;
  return true;
}

bool ScalarConverter::isPseudoLiteral(const std::string &str) {
  if (str == "nan" || str == "nanf") {
    floatValue = std::numeric_limits<float>::quiet_NaN();
    doubleValue = std::numeric_limits<double>::quiet_NaN();
    return true;
  } else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff") {
    floatValue = std::numeric_limits<float>::infinity();
    doubleValue = std::numeric_limits<double>::infinity();
    return true;
  } else if (str == "-inf" || str == "-inff") {
    floatValue = -std::numeric_limits<float>::infinity();
    doubleValue = -std::numeric_limits<double>::infinity();
    return true;
  }
  return false;
}

bool ScalarConverter::isInt(double temp, const std::string &str) {
  if (str.length() == 1 && !isdigit(str[0]))
    return false;
  if (str.length() > 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')
    return false;
  for (size_t i = 1; i < str.length(); i++) {
    if (!isdigit(str[i]))
      return false;
  }
  if (temp < std::numeric_limits<int>::min() ||
      temp > std::numeric_limits<int>::max())
    return false;
  intValue = static_cast<int>(temp);
  return true;
}

bool ScalarConverter::isFloat(double temp, const std::string &str) {
  if ((str.find('.') == std::string::npos) &&
      (str.find('f') == std::string::npos))
    return false;
  if (str[str.length() - 1] != 'f')
    return false;
  if (temp > std::numeric_limits<float>::max() ||
      temp < -std::numeric_limits<float>::max())
    return false;
  floatValue = static_cast<float>(temp);
  return true;
}

bool ScalarConverter::isDouble(double temp, const std::string &str) {
  if (str.find('.') == std::string::npos)
    return false;
  doubleValue = static_cast<double>(temp);
  return true;
}

int ScalarConverter::parseString(std::string const &str) {
  if (str.empty())
    return INVALID;
  if (isChar(str))
    return CHAR;
  if (!isValue(str))
    return INVALID;
  if (isPseudoLiteral(str))
    return PSEUDO;

  double temp = std::strtod(str.c_str(), NULL);
  if (isInt(temp, str))
    return INT;
  if (isFloat(temp, str))
    return FLOAT;
  if (isDouble(temp, str))
    return DOUBLE;
  return INVALID;
}

void ScalarConverter::fromChar() {
  std::cout << "char: '" << charValue << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(charValue) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(charValue) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(charValue) << std::endl;
}

void ScalarConverter::fromInt() {
  if (intValue < std::numeric_limits<char>::min() ||
      intValue > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible" << std::endl;
  } else if (isprint(intValue)) {
    std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
  std::cout << "int: " << intValue << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(intValue) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::fromFloat() {
  if (floatValue < std::numeric_limits<char>::min() ||
      floatValue > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible" << std::endl;
  } else if (isprint(floatValue)) {
    std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
  if (floatValue < std::numeric_limits<int>::min() ||
      floatValue > std::numeric_limits<int>::max()) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
            << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(floatValue) << std::endl;
}

void ScalarConverter::fromDouble() {
  if (doubleValue < std::numeric_limits<char>::min() ||
      doubleValue > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible" << std::endl;
  } else if (isprint(doubleValue)) {
    std::cout << "char: '" << static_cast<char>(doubleValue) << "'"
              << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }
  if (doubleValue < std::numeric_limits<int>::min() ||
      doubleValue > std::numeric_limits<int>::max()) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
  }
  if (doubleValue < -std::numeric_limits<float>::max()) {
    std::cout << "float: -inff" << std::endl;
  } else if (doubleValue > std::numeric_limits<float>::max()) {
    std::cout << "float: inff" << std::endl;
  } else {
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(doubleValue) << "f" << std::endl;
  }
  std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue
            << std::endl;
}

void ScalarConverter::fromPseudo() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << floatValue << "f" << std::endl;
  std::cout << "double: " << doubleValue << std::endl;
}