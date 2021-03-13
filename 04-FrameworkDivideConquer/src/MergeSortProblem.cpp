#include "MergeSortProblem.h"

MergeSortProblem::MergeSortProblem(std::vector<int> array)
    : Problema::Problema() {
  array_ = array;
}

bool MergeSortProblem::isCasoMinimo() { return array_.size() < 2; }

std::pair<Problema*, Problema*> MergeSortProblem::descomponer() {
  std::pair<Problema*, Problema*> subProblems;
  std::vector<int> left;
  std::vector<int> right;
  int middle = array_.size() / 2;
  for (size_t i = 0; i < array_.size(); i++) {
    if (i < middle) {
      left.push_back(array_[i]);
    } else {
      right.push_back(array_[i]);
    }
  }

  subProblems.first = new MergeSortProblem(left);
  subProblems.second = new MergeSortProblem(right);
  return subProblems;
}

void MergeSortProblem::solver(Solucion* s) { s->set_array(array_); }