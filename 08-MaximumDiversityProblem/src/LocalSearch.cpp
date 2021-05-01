#include "LocalSearch.hpp"

LocalSearch::LocalSearch(NeighbourAlgorithm* neighbour_algorithm) {
  neighbour_algorithm_ = neighbour_algorithm;
}

Solution LocalSearch::execute(Solution& solution) {
  Solution best_solution = solution;
  do {
    solution = best_solution;
    std::vector<Solution> neighbours =
        neighbour_algorithm_->generateNeighbour(solution);
    for (auto&& neighbour : neighbours) {
      if (neighbour.calculate_objetive_function() <
          best_solution.calculate_objetive_function()) {
        best_solution = neighbour;
      }
    }

  } while (best_solution.calculate_objetive_function() !=
           solution.calculate_objetive_function());
  return best_solution;
}
