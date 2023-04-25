#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed_point_value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  this->fixed_point_value = fixed.getRawBits();
}

Fixed::Fixed(const int integer) {
  std::cout << "Int constructor called" << std::endl;
  this->fixed_point_value = integer << fractional_bits;
}

Fixed::Fixed(const float floating_point) {
  std::cout << "Float constructor called" << std::endl;
  this->fixed_point_value = roundf(floating_point * (1 << fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixed_point_value = fixed.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return this->fixed_point_value; }

void Fixed::setRawBits(int const raw) { this->fixed_point_value = raw; }

float Fixed::toFloat(void) const {
  return (float)this->fixed_point_value / (1 << fractional_bits);
}

int Fixed::toInt(void) const {
  return this->fixed_point_value >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
