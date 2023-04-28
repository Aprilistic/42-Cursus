#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
private:
  std::vector<int> vec;
  unsigned int N;

  Span();
public:
  Span(unsigned int N);
  Span(const Span &copy);
  ~Span();
  
  Span &operator=(const Span &copy);


  void addNumber(int n);
  void addNumber(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end);

  int shortestSpan() const;
  int longestSpan() const;

  class NoSpanException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class FullSpanException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif // SPAN_HPP_