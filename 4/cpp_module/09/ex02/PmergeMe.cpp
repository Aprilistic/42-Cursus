#include "PmergeMe.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <sys/_types/_clock_t.h>
#include <vector>

std::vector<int> PmergeMe::v_origin;
std::vector<int> PmergeMe::v_sorted;
std::vector<int> PmergeMe::v;
std::list<int> PmergeMe::l;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) { (void)copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
  (void)copy;
  return *this;
}

bool PmergeMe::parseInput(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " [list of numbers]" << std::endl;
    return false;
  }

  for (int i = 1; i < argc; i++) {
    std::stringstream ss(argv[i]);
    int n;
    ss >> n;
    if (ss.fail() || !ss.eof()) {
      return false;
    }
    ss.clear();
    v_origin.push_back(n);
  }
  v_sorted = v_origin;
  sort(v_sorted.begin(), v_sorted.end());
  return true;
}

void PmergeMe::displaySequence() {
  std::cout << std::setw(10) << std::left << "Before: ";
  for (std::vector<int>::iterator it = v_origin.begin(); it != v_origin.end();
       it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << std::setw(10) << std::left << "After: ";
  for (std::vector<int>::iterator it = v_sorted.begin(); it != v_sorted.end();
       it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::mergeSort(std::vector<int> &v, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;
    mergeSort(v, left, middle);
    mergeSort(v, middle + 1, right);
    merge(v, left, middle, right);
  }
}

void PmergeMe::merge(std::vector<int> &v, int left, int middle, int right) {
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  std::vector<int> L(n1);
  std::vector<int> R(n2);

  for (i = 0; i < n1; i++)
    L[i] = v[left + i];
  for (j = 0; j < n2; j++)
    R[j] = v[middle + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      v[k] = L[i];
      i++;
    } else {
      v[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    v[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    v[k] = R[j];
    j++;
    k++;
  }
}

void PmergeMe::mergeSort(std::list<int> &l) {
  if (l.size() <= 1) {
    return;
  }

  std::list<int> result, left, right;
  int middle = l.size() / 2;
  int i = 0;
  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    if (i < middle) {
      left.push_back(*it);
    } else {
      right.push_back(*it);
    }
    i++;
  }

  mergeSort(left);
  mergeSort(right);
  merge(left, right, result);

  l = result;
}

void PmergeMe::merge(std::list<int> &left, std::list<int> &right,
                     std::list<int> &result) {
  while (!left.empty() && !right.empty()) {
    if (left.front() <= right.front()) {
      result.push_back(left.front());
      left.pop_front();
    } else {
      result.push_back(right.front());
      right.pop_front();
    }
  }
  while (!left.empty()) {
    result.push_back(left.front());
    left.pop_front();
  }
  while (!right.empty()) {
    result.push_back(right.front());
    right.pop_front();
  }
}

void PmergeMe::displayElapsedTimeOfMergeSort() {
  v.resize(v_origin.size());
  for (unsigned int i = 0; i < v_origin.size(); i++)
    v[i] = v_origin[i];
  for (unsigned int i = 0; i < v_origin.size(); i++)
    l.push_back(v_origin[i]);
  clock_t start, end;
  double elapsed_time;

  start = clock();
  mergeSort(v, 0, v.size() - 1);
  end = clock();
  elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << std::setw(5) << std::right
            << v_origin.size() << " elements : " << std::setw(10) << std::right
            << " elements with std::list : " << std::fixed
            << std::setprecision(5) << elapsed_time << " us" << std::endl;

  start = clock();
  mergeSort(l);
  end = clock();
  elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << std::setw(5) << std::right
            << v_origin.size() << " elements : " << std::setw(10) << std::right
            << " elements with std::list : " << std::fixed
            << std::setprecision(5) << elapsed_time << " us" << std::endl;
}

void PmergeMe::pmerge(int argc, char **argv) {
  if (!parseInput(argc, argv)) {
    std::cout << "Error" << std::endl;
    return;
  }

  displaySequence();
  displayElapsedTimeOfMergeSort();
}