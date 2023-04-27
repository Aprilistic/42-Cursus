#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

#include <iostream>

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T> T min(T &a, T &b) { return (a < b ? a : b); }

template <typename T> T max(T &a, T &b) { return (a > b ? a : b); }

#endif // WHATEVER_HPP_