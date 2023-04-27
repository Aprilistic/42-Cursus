#ifndef ITER_HPP_
#define ITER_HPP_

#include <iostream>

template <typename T> void iter(T *array, size_t length, void (*f)(T const &)) {
  for (size_t i = 0; i < length; i++)
    f(array[i]);
}

template <typename T> void print(T const &x) { std::cout << x << std::endl; }

#endif // ITER_HPP_