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
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP_