#include "Span.hpp"
#include <iostream>

Span::Span() {}

Span::Span(unsigned int N) : N(N) { vec.resize(0); }

Span::Span(const Span &copy) : N(copy.N) {
  vec.resize(N);
  for (unsigned int i = 0; i < N; i++)
    vec[i] = copy.vec[i];
}

Span::~Span() {}

Span &Span::operator=(const Span &copy) {
  N = copy.N;
  vec.resize(N);
  for (unsigned int i = 0; i < N; i++)
    vec[i] = copy.vec[i];
  return *this;
}

void Span::addNumber(int n) {
  if (vec.size() >= N)
    throw FullSpanException();
  vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  if (vec.size() + std::distance(begin, end) > N)
    throw FullSpanException();
  vec.insert(vec.end(), begin, end);
}

int Span::shortestSpan() const {
  if (vec.size() <= 1)
    throw NoSpanException();
  std::vector<int> tmp(vec);
  std::sort(tmp.begin(), tmp.end());
  int min = tmp[1] - tmp[0];
  for (unsigned int i = 2; i < tmp.size(); i++) {
    if (tmp[i] - tmp[i - 1] < min)
      min = tmp[i] - tmp[i - 1];
  }
  return min;
}

int Span::longestSpan() const {
  if (vec.size() <= 1)
    throw NoSpanException();
  std::vector<int> tmp(vec);
  std::sort(tmp.begin(), tmp.end());
  return tmp[tmp.size() - 1] - tmp[0];
}

const char *Span::NoSpanException::what() const throw() {
  return "No span to find";
}

const char *Span::FullSpanException::what() const throw() {
  return "Span is full";
}
