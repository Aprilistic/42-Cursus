#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed_point_value(0) {}

Fixed::Fixed(const Fixed &fixed) {
  this->fixed_point_value = fixed.getRawBits();
}

Fixed::Fixed(const int integer) {
  this->fixed_point_value = integer << fractional_bits;
}

Fixed::Fixed(const float floating_point) {
  this->fixed_point_value = roundf(floating_point * (1 << fractional_bits));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &fixed) {
  this->fixed_point_value = fixed.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &fixed) {
  return this->fixed_point_value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) {
  return this->fixed_point_value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) {
  return this->fixed_point_value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) {
  return this->fixed_point_value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) {
  return this->fixed_point_value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) {
  return this->fixed_point_value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) {
  return Fixed(fixed.toFloat() + this->toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
  return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) {
  return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
  return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
  this->fixed_point_value++;
  return *this;
}

Fixed &Fixed::operator--() {
  this->fixed_point_value--;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  this->fixed_point_value++;
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->fixed_point_value--;
  return tmp;
}

int Fixed::getRawBits(void) const { return this->fixed_point_value; }

void Fixed::setRawBits(int const raw) { this->fixed_point_value = raw; }

float Fixed::toFloat(void) const {
  return (float)this->fixed_point_value / (1 << fractional_bits);
}

int Fixed::toInt(void) const {
  return this->fixed_point_value >> fractional_bits;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a.getRawBits() > b.getRawBits() ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return a.getRawBits() > b.getRawBits() ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
