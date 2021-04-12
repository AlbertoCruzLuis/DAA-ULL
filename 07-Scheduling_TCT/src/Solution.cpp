#include "Solution.hpp"

Solution::Solution(int machine_numbers) {
  list_machines_.resize(machine_numbers);
}

std::vector<Machine> Solution::get_list_machines() { return list_machines_; }

void Solution::add_task(std::pair<int, int> task, int machine) {
  list_machines_[machine].add_task(task);
}

int Solution::assigned_tasks() {
  int assigned_tasks = 0;
  for (auto&& machine : list_machines_) {
    assigned_tasks += machine.assigned_tasks();
  }
  return assigned_tasks;
}

int Solution::calculate_objetive_function() const {
  int objetive_function = 0;
  for (auto&& machine : list_machines_) {
    objetive_function += machine.calculate_tct();
  }
  return objetive_function;
}

std::pair<int, int> Solution::find_task_to_add(Graph& graph,
                                               int current_machine) {
  std::vector<std::pair<int, int>> all_proccessed_tasks;
  for (auto&& machine : list_machines_) {
    for (auto&& task : machine.get_processed_tasks()) {
      all_proccessed_tasks.push_back(task);
    }
  }
  int index_last_proccessed_task =
      list_machines_[current_machine]
          .get_processed_tasks()
              [list_machines_[current_machine].get_processed_tasks().size() - 1]
          .first;

  return graph.min_element_of_row(all_proccessed_tasks,
                                  index_last_proccessed_task);
}

std::ostream& operator<<(std::ostream& os, const Solution& solution) {
  for (auto&& machine : solution.list_machines_) {
    os << machine << "\n";
  }
  os << "Objetive Function: " << solution.calculate_objetive_function();

  return os;
}
