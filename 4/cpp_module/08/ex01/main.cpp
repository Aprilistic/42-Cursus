#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  // exception
  try {
    sp.addNumber(33);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << "consecutive sequence of 10000 numbers: " << std::endl;
  Span test1 = Span(10000);
  for (int i = 0; i < 10000; ++i)
    test1.addNumber(i);
  std::cout << test1.shortestSpan() << std::endl;
  std::cout << test1.longestSpan() << std::endl;

  std::cout << "random sequence of 10000 numbers: " << std::endl;
  Span test2 = Span(10000);
  std::vector<int> vec(10000);
  for (int i = 0; i < 10000; ++i)
    vec[i] = std::rand();
  test2.addNumber(vec.begin(), vec.end());
  std::cout << test2.shortestSpan() << std::endl;
  std::cout << test2.longestSpan() << std::endl;

  // exception
  try {
    Span test3 = Span(1);
    test3.addNumber(1);
    test3.shortestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}