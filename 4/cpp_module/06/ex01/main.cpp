#include "Serializer.hpp"
#include <iostream>

int main() {
  Data *data = new Data;
  data->str = "Hello World!";
  std::cout << "data->str: " << data->str << std::endl
            << "addr: " << &data << std::endl;
  uintptr_t raw = Serializer::serialize(data);
  Data *ptr = Serializer::deserialize(raw);
  std::cout << "ptr->str: " << ptr->str << std::endl
            << "addr: " << &ptr << std::endl;
  delete ptr;
  return 0;
}