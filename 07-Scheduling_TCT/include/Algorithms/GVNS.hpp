#ifndef GVNS_H
#define GVNS_H

#include <vector>

#include "Algorithm.hpp"
#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class GVNS : public Algorithm {
 private:
  int MAX_ITERATIONS_ = 100;
  int VALUE_ENVIRONMENTAL_STRUCTURE = 5;

 public:
  GVNS(int value_environmental_structure = 5, int max_iterations = 100);

  Solution execute(Graph &graph);
  Solution generate_boot_solution(Graph &graph);
  int calculate_size_min_sequence(Solution &solution);
  Solution shaking(Solution &solution, int size_environmental_structure);
  Solution vnd(Solution &solution);
  std::vector<NeighbourAlgorithm *> generate_environmental_structure(
      int size_environmetal_structure);
  Solution calculate_min_tct_of_environmental_structure(
      std::vector<NeighbourAlgorithm *> environmental_structures,
      Solution &solution);
};
#endif  // GVNS_H