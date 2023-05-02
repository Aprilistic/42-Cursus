#include "PmergeMe.hpp"

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
    if (n < 0) {
      return false;
    }
    v_origin.push_back(n);
  }
  v_sorted = v_origin;
  sort(v_sorted.begin(), v_sorted.end());
  v = v_origin;
  l = std::list<int>(v_origin.begin(), v_origin.end());
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

void PmergeMe::mergeSort(std::vector<int> &v) { mergeSort(v, 0, v.size() - 1); }

void PmergeMe::mergeSort(std::vector<int> &v, int left, int right) {
  if (right - left < INSERTION_SORT_THRESHOLD) {
    insertionSort(v, left, right);
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(v, left, mid);
  mergeSort(v, mid + 1, right);
  merge(v, left, mid, right);
}

void PmergeMe::insertionSort(std::vector<int> &v, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = v[i];
    int j = i - 1;
    while (j >= left && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

void PmergeMe::merge(std::vector<int> &v, int left, int mid, int right) {
  std::vector<int> tmp(right - left + 1);
  int i = left;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= right) {
    if (v[i] <= v[j]) {
      tmp[k] = v[i];
      i++;
    } else {
      tmp[k] = v[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    tmp[k] = v[i];
    i++;
    k++;
  }
  while (j <= right) {
    tmp[k] = v[j];
    j++;
    k++;
  }
  for (int i = left; i <= right; i++) {
    v[i] = tmp[i - left];
  }
}

std::list<int>::iterator PmergeMe::find_middle(std::list<int> &l) {
  std::list<int>::iterator it = l.begin();
  std::advance(it, std::distance(l.begin(), l.end()) / 2);
  return it;
}

void PmergeMe::mergeSort(std::list<int> &l) {
  if (l.size() < INSERTION_SORT_THRESHOLD) {
    insertionSort(l);
    return;
  }
  std::list<int> left;
  std::list<int> right;

  left.splice(left.begin(), l, l.begin(), find_middle(l));
  right.splice(right.end(), l);
  mergeSort(left);
  mergeSort(right);
  merge(left, right, l);
}

void PmergeMe::insertionSort(std::list<int> &l) {
  for (std::list<int>::iterator i = ++l.begin(); i != l.end(); ++i) {
    int key = *i;
    std::list<int>::iterator j = i;
    --j;
    while (j != l.begin() && *j > key) {
      *i = *j;
      --i;
      --j;
    }
    *j = key;
  }
}

void PmergeMe::merge(std::list<int> &left, std::list<int> &right,
                     std::list<int> &result) {
  std::list<int>::iterator left_it = left.begin();
  std::list<int>::iterator right_it = right.begin();

  while (left_it != left.end() && right_it != right.end()) {
    if (*left_it < *right_it) {
      result.push_back(*left_it);
      ++left_it;
    } else {
      result.push_back(*right_it);
      ++right_it;
    }
  }

  while (left_it != left.end()) {
    result.push_back(*left_it);
    ++left_it;
  }

  while (right_it != right.end()) {
    result.push_back(*right_it);
    ++right_it;
  }
}

void PmergeMe::displayElapsedTimeOfMergeSort() {
  clock_t start, end;
  double elapsed_time;

  start = clock();
  mergeSort(v);
  end = clock();
  elapsed_time = static_cast<double>(end - start);
  std::cout << "Time to process a range of " << std::setw(5) << std::right
            << v_origin.size() << " elements : " << std::setw(20) << std::right
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5) << elapsed_time << " us" << std::endl;

  start = clock();
  mergeSort(l);
  end = clock();
  elapsed_time = static_cast<double>(end - start);
  std::cout << "Time to process a range of " << std::setw(5) << std::right
            << v_origin.size() << " elements : " << std::setw(20) << std::right
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
