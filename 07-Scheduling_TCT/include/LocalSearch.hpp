#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"
#include "Solution.hpp"

class LocalSearch {
 private:
  NeighbourAlgorithm* neighbour_algorithm_;

 public:
  LocalSearch(NeighbourAlgorithm* neighbour_algorithm);
  ~LocalSearch() { delete neighbour_algorithm_; }

  Solution run(Solution& solution);
  Solution optimal_search(Solution& solution);
  Solution stop_criterion(Solution& solution);
};
#endif  // LOCALSEARCH_H