#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

Base *generate(void) {
  int i = std::rand() % 3;
  if (i == 0)
    return new A();
  else if (i == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
  } catch (std::bad_cast &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
  } catch (std::bad_cast &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
  } catch (std::bad_cast &e) {
  }
}

int main(void) {
  std::srand(std::time(NULL));
  Base *p = generate();

  identify(p);
  identify(*p);

  delete p;
  return 0;
}