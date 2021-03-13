#include "MergeSortSolution.h"

MergeSortSolution::MergeSortSolution() : Solucion::Solucion() {}

void MergeSortSolution::resolver() { std::cout << this << std::endl; }

void MergeSortSolution::mezcla(std::pair<Solucion*, Solucion*> subSolutions) {
  std::vector<int> left = subSolutions.first->get_array();
  std::vector<int> right = subSolutions.second->get_array();

  while (left.size() > 0 && right.size() > 0) {
    if (left.front() <= right.front()) {
      array_.push_back(left.front());
      left.erase(left.begin());
    } else {
      array_.push_back(right.front());
      right.erase(right.begin());
    }
  }
  if (left.size() > 0) {
    for (auto&& element : left) {
      array_.push_back(element);
    }
  }
  if (right.size() > 0) {
    for (auto&& element : right) {
      array_.push_back(element);
    }
  }
}

Solucion* MergeSortSolution::getInstance() { return new MergeSortSolution(); }