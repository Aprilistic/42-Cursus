#ifndef FIXED_HPP_
#define FIXED_HPP_
#include <iostream>
#include <ostream>

class Fixed {
private:
  int fixed_point_value;
  static const int fractional_bits = 8;

public:
  Fixed();
  Fixed(const Fixed &fixed);
  Fixed(const int integer);
  Fixed(const float floating_point);
  ~Fixed();

  Fixed &operator=(const Fixed &fixed);

  bool operator>(const Fixed &fixed);
  bool operator<(const Fixed &fixed);
  bool operator>=(const Fixed &fixed);
  bool operator<=(const Fixed &fixed);
  bool operator==(const Fixed &fixed);
  bool operator!=(const Fixed &fixed);

  Fixed operator+(const Fixed &fixed);
  Fixed operator-(const Fixed &fixed);
  Fixed operator*(const Fixed &fixed);
  Fixed operator/(const Fixed &fixed);

  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  static const Fixed &min(const Fixed &a, const Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP_