#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &copy) { (void)copy; }

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &copy) {
  (void)copy;
  return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
  uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
  return raw;
}

Data *Serializer::deserialize(uintptr_t raw) {
  Data *ptr = reinterpret_cast<Data *>(raw);
  return ptr;
}

