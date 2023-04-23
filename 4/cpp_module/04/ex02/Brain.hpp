#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <iostream>
#include <string>

class Brain {
private:
  std::string ideas[100];

public:
  Brain();
  Brain(const Brain &copy);
  ~Brain();

  Brain &operator=(const Brain &copy);

  std::string getIdea(int index) const;
  void setIdea(int index, std::string idea);
};

#endif // BRAIN_HPP_