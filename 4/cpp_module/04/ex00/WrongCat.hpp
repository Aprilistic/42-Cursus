#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &copy);
  ~WrongCat();

  WrongCat &operator=(const WrongCat &copy);

  void makeSound() const;
};

#endif // WRONGCAT_HPP_