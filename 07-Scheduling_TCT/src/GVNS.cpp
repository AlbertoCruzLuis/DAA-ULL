#include "Algorithms/GVNS.hpp"

#include <algorithm>
#include <limits>

#include "LocalSearch.hpp"
#include "NeighbourAlgorithms/ExchangeExternalMachine.hpp"
#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"
#include "NeighbourAlgorithms/ReinsertionExternalMachine.hpp"

GVNS::GVNS(int value_environmental_structure, int max_iterations) {
  VALUE_ENVIRONMENTAL_STRUCTURE = value_environmental_structure;
  MAX_ITERATIONS_ = max_iterations;
}

Solution GVNS::execute(Graph &graph) {
  Solution best_solution = generate_boot_solution(graph);

  for (size_t i = 0; i < MAX_ITERATIONS_; i++) {
    int size_environmental_structure = 1;
    int size_min_sequence = calculate_size_min_sequence(best_solution);
    int max_size_environmental_structure =
        std::min(size_min_sequence, VALUE_ENVIRONMENTAL_STRUCTURE);

    do {
      Solution oneSolution =
          shaking(best_solution, size_environmental_structure);
      Solution twoSolution = vnd(oneSolution);
      if (twoSolution.calculate_objetive_function() <
          best_solution.calculate_objetive_function()) {
        best_solution = twoSolution;
        size_environmental_structure = 1;
      } else {
        size_environmental_structure++;
      }
    } while (size_environmental_structure < max_size_environmental_structure);
  }
  return best_solution;
}

Solution GVNS::generate_boot_solution(Graph &graph) {
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

int GVNS::calculate_size_min_sequence(Solution &solution) {
  int size_min_sequence = std::numeric_limits<int>::max();
  for (auto &&machine : solution.get_list_machines()) {
    if (machine.get_processed_tasks().size() < size_min_sequence) {
      size_min_sequence = machine.get_processed_tasks().size();
    }
  }
  return size_min_sequence;
}

Solution GVNS::shaking(Solution &solution, int size_environmental_structure) {
  Solution oneSolution = solution;
  int r = 0;
  do {
    LocalSearch local_search(new ReinsertionExternalMachine());
    oneSolution = local_search.run(oneSolution);
    r++;
  } while (r < size_environmental_structure);
  return oneSolution;
}

Solution GVNS::vnd(Solution &solution) {
  Solution best_solution = solution;
  do {
    solution = best_solution;
    int size_environmental_structure = 1;
    int size_min_sequence = calculate_size_min_sequence(best_solution);
    int max_size_environmental_structure =
        std::min(size_min_sequence, VALUE_ENVIRONMENTAL_STRUCTURE);
    do {
      std::vector<NeighbourAlgorithm *> environmental_structures =
          generate_environmental_structure(max_size_environmental_structure);
      Solution one_solution = calculate_min_tct_of_environmental_structure(
          environmental_structures, best_solution);
      if (one_solution.calculate_objetive_function() <
          best_solution.calculate_objetive_function()) {
        best_solution = one_solution;
        size_environmental_structure = 1;
      } else {
        size_environmental_structure++;
      }
    } while (size_environmental_structure < max_size_environmental_structure);
  } while (solution.calculate_objetive_function() >
           best_solution.calculate_objetive_function());
  return best_solution;
}

std::vector<NeighbourAlgorithm *> GVNS::generate_environmental_structure(
    int size_environmetal_structure) {
  std::vector<NeighbourAlgorithm *> environmental_structures;
  for (size_t i = 0; i < size_environmetal_structure; i++) {
    if (i % 2 == 0) {
      environmental_structures.push_back(new ReinsertionExternalMachine());
    } else {
      environmental_structures.push_back(new ExchangeExternalMachine());
    }
  }

  return environmental_structures;
}

Solution GVNS::calculate_min_tct_of_environmental_structure(
    std::vector<NeighbourAlgorithm *> environmental_structures,
    Solution &solution) {
  Solution best_solution = solution;
  for (size_t i = 0; i < environmental_structures.size(); i++) {
    LocalSearch local_search(environmental_structures[i]);
    Solution oneSolution = local_search.run(best_solution);
    if (oneSolution.calculate_objetive_function() <
        best_solution.calculate_objetive_function()) {
      best_solution = oneSolution;
    }
  }
  return best_solution;
}
