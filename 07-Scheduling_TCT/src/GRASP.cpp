#include "Algorithms/GRASP.hpp"

#include <algorithm>

#include "LocalSearch.hpp"

GRASP::GRASP(NeighbourAlgorithm *neighbour_algorithm, int max_iterations,
             int size_rcl) {
  MAX_ITERATIONS_ = max_iterations;
  SIZE_RCL = size_rcl;
  neighbour_algorithm_ = neighbour_algorithm;
}

GRASP::~GRASP() { delete neighbour_algorithm_; }

Solution GRASP::execute(Graph &graph) {
  std::cout << "\nGRASP execute" << std::endl;
  Solution solution(graph.get_machines_number());
  LocalSearch local_search(neighbour_algorithm_);
  Solution best_solution = greedy_randomized_construction(graph);
  srand(time(NULL));
  for (size_t i = 0; i < MAX_ITERATIONS_; i++) {
    solution = greedy_randomized_construction(graph);
    solution = local_search.run(solution);
    if (solution.calculate_objetive_function() <
        best_solution.calculate_objetive_function()) {
      best_solution = solution;
    }
  }
  return best_solution;
}

Solution GRASP::greedy_randomized_construction(Graph &graph) {
  Solution solution(graph.get_machines_number());
  // Evaluate the incremental costs of the candidate elements
  int current_machine = 0;
  while (solution.assigned_tasks() < graph.get_tasks_number()) {
    // Build the restricted candidate list (RCL)
    std::vector<Task> rcl =
        build_RCL(graph, solution, current_machine, SIZE_RCL);
    // Select an element s from the RCL at random
    Task candidate = select_random_candidate(rcl);
    // Solution ← Solution ∪ {s}
    current_machine = find_machine_min_tct(solution);
    solution.add_task(candidate, current_machine);
    // Reevaluate the incremental costs
  }
  return solution;
}

std::vector<Task> GRASP::build_RCL(Graph &graph, Solution &solution,
                                   int current_machine, int size_rcl) {
  std::vector<Task> rcl = graph.unprocessed_tasks(
      solution.all_proccessed_tasks(),
      solution.get_index_last_proccessed_task(current_machine));

  int real_size_rcl = rcl.size() < size_rcl ? rcl.size() : size_rcl;
  std::nth_element(rcl.begin(), rcl.begin() + real_size_rcl, rcl.end(),
                   [](Task before_task, Task after_task) {
                     return before_task.get_value_of_arc() <
                            after_task.get_value_of_arc();
                   });

  std::vector<Task> rclTopThree;
  std::copy(rcl.begin(), rcl.begin() + real_size_rcl,
            std::back_inserter(rclTopThree));

  return rclTopThree;
}

Task GRASP::select_random_candidate(std::vector<Task> rcl) {
  int index = 0;
  if (rcl.size()) {
    index = rand() % rcl.size();
  }
  return rcl[index];
}

int GRASP::find_machine_min_tct(Solution solution) {
  int index_of_current_machine = 0;
  int min_tct = std::numeric_limits<int>::max();
  Task machine_min_tct = Task(min_tct, index_of_current_machine);
  for (auto &&machine : solution.get_list_machines()) {
    int current_tct = machine.calculate_tct();
    if (current_tct < machine_min_tct.get_id_task()) {
      machine_min_tct.set_id_task(current_tct);
      machine_min_tct.set_value_of_arc(index_of_current_machine);
    }
    index_of_current_machine++;
  }
  return machine_min_tct.get_value_of_arc();
}
