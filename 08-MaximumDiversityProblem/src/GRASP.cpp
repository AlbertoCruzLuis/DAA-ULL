#include "Algorithms/GRASP.hpp"

#include <algorithm>

#include "LocalSearch.hpp"

GRASP::GRASP(int size_solution, NeighbourAlgorithm *neighbour_algorithm,
             int size_rcl, int max_iterations) {
  size_solution_ = size_solution;
  neighbour_algorithm_ = neighbour_algorithm;
  SIZE_RCL = size_rcl;
  MAX_ITERATIONS_ = max_iterations;
}

Solution GRASP::execute(Problem &problem) {
  Solution solution;
  Solution best_solution = greedy_randomized_construction(problem);
  LocalSearch local_search(neighbour_algorithm_);
  srand(time(NULL));
  // Stop criterion
  for (size_t i = 0; i < MAX_ITERATIONS_; i++) {
    solution = greedy_randomized_construction(problem);
    solution = local_search.execute(solution);
    if (solution.calculate_objetive_function() >
        best_solution.calculate_objetive_function()) {
      best_solution = solution;
    }
  }
  return best_solution;
}

Solution GRASP::greedy_randomized_construction(Problem &problem) {
  Solution solution;
  Point random_point = select_random_candidate(problem.get_list_points());
  solution.add_point(random_point);

  while (solution.get_list_points().size() < size_solution_) {
    std::vector<Point> rcl = build_RCL(problem, solution);
    Point candidate = select_random_candidate(rcl);
    solution.add_point(candidate);
  }
  return solution;
}

std::vector<Point> GRASP::build_RCL(Problem &problem, Solution &solution) {
  std::vector<Point> candidates =
      problem.unproccessed_points(solution.get_list_points());

  // Get current rcl in case of that the size of rcl get for user is not valid
  int real_size_rcl =
      candidates.size() < SIZE_RCL ? candidates.size() : SIZE_RCL;

  std::vector<std::pair<float, Point>> list_objetive_function_by_each_point;

  for (auto &&point : candidates) {
    solution.add_point(point);
    float objetive_function_for_this_point =
        solution.calculate_objetive_function();
    solution.get_list_points().pop_back();

    int position_to_insert = 0;
    for (auto &&objetive_function : list_objetive_function_by_each_point) {
      if (objetive_function_for_this_point < objetive_function.first) {
        position_to_insert++;
      }
    }
    list_objetive_function_by_each_point.insert(
        list_objetive_function_by_each_point.begin() + position_to_insert,
        std::make_pair(objetive_function_for_this_point, point));
  }

  // Choose the K Best values
  std::vector<Point> rclTopElements;
  for (int i = 0; i < real_size_rcl; i++) {
    rclTopElements.push_back(list_objetive_function_by_each_point[i].second);
  }

  return rclTopElements;
}

Point GRASP::select_random_candidate(std::vector<Point> rcl) {
  int index = 0;
  if (rcl.size()) {
    index = rand() % rcl.size();
  }
  return rcl[index];
}
