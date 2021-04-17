#include "MultiBoot.hpp"

#include "LocalSearch.hpp"

MultiBoot::MultiBoot(NeighbourAlgorithm *neighbour_algorithm,
                     int max_iterations) {
  neighbour_algorithm_ = neighbour_algorithm;
  MAX_ITERATIONS_ = max_iterations;
}

MultiBoot::~MultiBoot() { delete neighbour_algorithm_; }

Solution MultiBoot::execute(Graph &graph) {
  std::cout << "MultiBoot execute" << std::endl;
  LocalSearch local_search(neighbour_algorithm_);
  Solution solution = generate_boot_solution(graph);
  Solution best_solution = solution;
  int iteration = 0;
  while (iteration < MAX_ITERATIONS_) {
    solution = local_search.run(solution);
    if (solution.calculate_objetive_function() <
        best_solution.calculate_objetive_function()) {
      best_solution = solution;
    }
    iteration++;
  }
  return best_solution;
}

Solution MultiBoot::generate_boot_solution(Graph &graph) {
  Solution solution(graph.get_machines_number());
  int task_index = 0;
  int number_of_task = graph.get_values_of_arcs().size() - 1;
  int number_of_machines = graph.get_machines_number();
  int task_by_each_machine = number_of_task / number_of_machines;
  for (auto &&list_task : graph.get_values_of_arcs()) {
    int machine = (task_index / task_by_each_machine) % number_of_machines;

    if (task_index != 0) {
      solution.add_task(list_task[task_index], machine);
    }
    task_index++;
  }
  return solution;
}
