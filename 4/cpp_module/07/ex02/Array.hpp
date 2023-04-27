#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *array;
  std::size_t length;

public:
  Array();
  Array(std::size_t n);
  Array(const Array &copy);
  ~Array();
  Array &operator=(const Array &copy);

  T &operator[](unsigned int i);

  std::size_t size() const;
};

template <typename T> Array<T>::Array() : array(NULL), length(0) {}

template <typename T>
Array<T>::Array(std::size_t n) : array(new T[n]), length(n) {}

template <typename T>
Array<T>::Array(const Array &copy)
    : array(new T[copy.length]), length(copy.length) {
  for (std::size_t i = 0; i < copy.length; i++) {
    array[i] = copy.array[i];
  }
}

template <typename T> Array<T>::~Array() { delete[] array; }

template <typename T> Array<T> &Array<T>::operator=(const Array &copy) {
  if (this != &copy) {
    delete[] array;
    array = new T[copy.length];
    length = copy.length;
    for (std::size_t i = 0; i < copy.length; i++) {
      array[i] = copy.array[i];
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int i) {
  if (i >= length) {
    throw std::exception();
  }
  return array[i];
}

template <typename T> std::size_t Array<T>::size() const { return length; }

#endif // ARRAY_HPP_