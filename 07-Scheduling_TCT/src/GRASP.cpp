#include "GRASP.hpp"

#include <algorithm>

Solution GRASP::execute(Graph &graph) {
  std::cout << "GRASP execute" << std::endl;
  Solution solution(graph.get_machines_number());
  for (size_t i = 0; i < MAX_ITERATIONS_; i++) {
    solution = greedy_randomized_construction(graph);
    // Solution ← Local Search(Solution)
    // Update Solution(Solution,Best Solution)
  }
  return solution;
}

Solution GRASP::greedy_randomized_construction(Graph &graph) {
  Solution solution(graph.get_machines_number());
  // Evaluate the incremental costs of the candidate elements
  int current_machine = 0;
  while (solution.assigned_tasks() < graph.get_tasks_number()) {
    // Build the restricted candidate list (RCL)
    std::vector<Task> rcl = build_RCL(graph, solution, current_machine);
    // Select an element s from the RCL at random
    Task candidate = select_random_candidate(rcl);
    // Solution ← Solution ∪ {s}
    current_machine = find_machine_min_tct(solution);
    solution.add_task(candidate, current_machine);
    // Reevaluate the incremental costs
  }
  return solution;
}

std::vector<Task> GRASP::build_RCL(Graph &graph, Solution solution,
                                   int current_machine) {
  std::vector<Task> rcl = graph.unprocessed_tasks(
      solution.all_proccessed_tasks(),
      solution.get_index_last_proccessed_task(current_machine));

  return rcl;
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
