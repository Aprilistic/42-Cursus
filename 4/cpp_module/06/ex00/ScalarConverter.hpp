#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define PSEUDO 4
#define INVALID 5


class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &copy);
  ~ScalarConverter();

  ScalarConverter &operator=(ScalarConverter const &copy);

  static char charValue;
  static int intValue;
  static float floatValue;
  static double doubleValue;

  static bool isChar(std::string const &str);
  static bool isPseudoLiteral(std::string const &str);
  static bool isInt(double temp, std::string const &str);
  static bool isFloat(double temp, std::string const &str);
  static bool isDouble(double temp, std::string const &str);

  static int parseString(std::string const &str);

  static void fromChar();
  static void fromInt();
  static void fromFloat();
  static void fromDouble();
  static void fromPseudo();

public:
  static void convert(std::string const &str);

};
#endif // SCALARCONVERTER_HPP_