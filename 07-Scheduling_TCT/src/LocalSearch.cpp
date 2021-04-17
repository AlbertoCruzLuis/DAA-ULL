#include "LocalSearch.hpp"

LocalSearch::LocalSearch(NeighbourAlgorithm *neighbour_algorithm) {
  neighbour_algorithm_ = neighbour_algorithm;
}

Solution LocalSearch::run(Solution solution) {
  return stop_criterion(solution);
}

Solution LocalSearch::optimal_search(Solution solution) {
  Solution neighbour;
  neighbour_algorithm_->set_solution_to_swap(solution);
  do {
    neighbour = neighbour_algorithm_->execute(solution);
    if (neighbour.calculate_objetive_function() <
        solution.calculate_objetive_function()) {
      solution = neighbour;
    }
  } while (neighbour.calculate_objetive_function() >
           solution.calculate_objetive_function());
  return solution;
}

Solution LocalSearch::stop_criterion(Solution current_solution) {
  int without_improvement = 0;
  Solution best_solution = current_solution;

  while (without_improvement < 3) {
    current_solution = optimal_search(current_solution);

    if (current_solution.calculate_objetive_function() >=
        best_solution.calculate_objetive_function()) {
      without_improvement++;
    } else {
      best_solution = current_solution;
      without_improvement = 0;
    }
  }
  return best_solution;
}
