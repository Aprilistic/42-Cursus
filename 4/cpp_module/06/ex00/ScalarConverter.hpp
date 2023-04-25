#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>
#include <string>
#include <exception>
#include <limits>

class ScalarConverter {
private:
  std::string literal;

  ScalarConverter();
public:
  ScalarConverter(std::string literal);
  ScalarConverter(ScalarConverter const &copy);
  ~ScalarConverter();

  ScalarConverter &operator=(ScalarConverter const &copy);

  operator char() const;
  operator int() const;
  operator float() const;
  operator double() const;
 
  class ImpossibleException : public std::exception {
  public:
    ImpossibleException();
    ImpossibleException(ImpossibleException const &copy);
    ~ImpossibleException() throw();

    ImpossibleException &operator=(ImpossibleException const &copy);

    virtual const char *what() const throw();
  };

  class NonDisplayableException : public std::exception {
  public:
    NonDisplayableException();
    NonDisplayableException(NonDisplayableException const &copy);
    ~NonDisplayableException() throw();

    NonDisplayableException &operator=(NonDisplayableException const &copy);

    virtual const char *what() const throw();
  };
};

#endif // SCALARCONVERTER_HPP_