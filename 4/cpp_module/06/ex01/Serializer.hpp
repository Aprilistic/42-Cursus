#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <iostream>
#include <string>
#include <sys/_types/_uintptr_t.h>

struct Data {
  std::string s1;
};

class Serializer {
private:
  std::string _randomString(int len);

  Serializer();
  ~Serializer();
  Serializer(Serializer const &src);
  Serializer &operator=(Serializer const &rhs);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP_