#include "QuickSortProblem.h"

QuickSortProblem::QuickSortProblem(std::vector<int> array)
    : Problema::Problema() {
  array_ = array;
}

bool QuickSortProblem::isCasoMinimo() { return array_.size() < 2; }

std::pair<Problema *, Problema *> QuickSortProblem::descomponer() {
  std::pair<Problema *, Problema *> subProblems;
  std::vector<int> left;
  std::vector<int> right;
  int pivot = array_.size() / 2;
  int low = 0;
  int high = array_.size() - 1;
  while (low < high) {
    if (array_[low] <= array_[pivot]) {
      low++;
    } else {
      swap(array_[low], array_[pivot]);
      high--;
    }
  }

  for (size_t i = 0; i < array_.size(); i++) {
    if (i < pivot) {
      left.push_back(array_[i]);
    } else {
      right.push_back(array_[i]);
    }
  }
  subProblems.first = new QuickSortProblem(left);
  subProblems.second = new QuickSortProblem(right);
  return subProblems;
}

void QuickSortProblem::solver(Solucion *s) { s->set_array(array_); }

void QuickSortProblem::swap(int &first, int &second) {
  int temporary = first;
  first = second;
  second = temporary;
}