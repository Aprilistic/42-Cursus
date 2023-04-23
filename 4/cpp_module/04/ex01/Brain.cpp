#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &copy) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = copy;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain &Brain::operator=(const Brain &copy) {
  std::cout << "Brain assignation operator called" << std::endl;
  if (this != &copy) {
    for (int i = 0; i < 100; i++)
      ideas[i] = copy.ideas[i];
  }
  return *this;
}

std::string Brain::getIdea(int index) const { return ideas[index]; }
void Brain::setIdea(int index, std::string idea) { ideas[index] = idea; }