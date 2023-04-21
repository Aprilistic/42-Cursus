#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
private:
  int fixed_point_value;
  static const int fractional_bits = 8;

public:
  Fixed();
  Fixed(const Fixed &fixed);
  ~Fixed();
  Fixed &operator=(const Fixed &fixed);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif // FIXED_HPP_