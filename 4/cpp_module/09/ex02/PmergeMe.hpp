#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

class PmergeMe {
private:
  PmergeMe();
  PmergeMe(PmergeMe const &copy);
  ~PmergeMe();

  PmergeMe &operator=(PmergeMe const &copy);

  static std::vector<int> v_origin;
  static std::vector<int> v_sorted;
  static std::vector<int> v;
  static std::list<int> l;


  static bool parseInput(int argc, char **argv);
  static void displaySequence();

  static void mergeSort(std::vector<int> &v, int left, int right);
  static void merge(std::vector<int> &v, int left, int middle, int right);

  static void mergeSort(std::list<int> &l);
  static void merge(std::list<int> &left, std::list<int> &right, std::list<int> &result);

  static void displayElapsedTimeOfMergeSort();
public:
  static void pmerge(int argc, char **argv);
};

#endif // PMERGEME_HPP_