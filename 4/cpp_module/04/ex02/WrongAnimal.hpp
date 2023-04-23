#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <iostream>
#include <string>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &copy);
  virtual ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &copy);

  std::string getType() const;
  void makeSound() const;
};

#endif // WRONGANIMAL_HPP_