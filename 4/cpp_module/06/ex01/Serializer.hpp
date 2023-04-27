#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <iostream>
#include <string>
#include <sys/_types/_uintptr_t.h>

struct Data {
  std::string str;
};

class Serializer {
private:
  Serializer();
  Serializer(Serializer const &copy);
  ~Serializer();
  Serializer &operator=(Serializer const &copy);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP_