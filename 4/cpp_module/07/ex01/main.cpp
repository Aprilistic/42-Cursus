#include "iter.hpp"
#include <iostream>

int main() {
  int array1[] = {1, 2, 3, 4, 5};
  iter(array1, 5, print);

  std::string array2[] = {"Hello", "World", "!"};
  iter(array2, 3, print);
  
  return 0;
}