#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  try {
    std::cout << *easyfind(v, 5) << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not found" << std::endl;
  }

  try {
    std::cout << *easyfind(v, 10) << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not found" << std::endl;
  }

  return 0;
}